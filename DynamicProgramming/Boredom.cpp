/*
Gary is bored and wants to play an interesting but tough game . So he figured out a new board game called "destroy the neighbours" . In this game there are N integers on a board. In one move, he can pick any integer x from the board and then all the integers with value x+1 or x-1 gets destroyed .This move will give him x points.
He plays the game until the board becomes empty . But as he want show this game to his friend Steven, he wants to learn techniques to maximise the points to show off . Can you help Gary in finding out the maximum points he receive grab from the game ?
Input Format :
First line will contain T (number of test case), each test case is consists of two line.
Line 1: Integer N 
Line 2: A list of N integers
Output Format :
For each test case print maximum points, Gary can receive from the Game setup in a newline.
Constraints :
 1 <= T <= 50
 1 <= N <= 10^5
 1 <= A[i] <= 1000
Sample Input :
1
2
1 2
Sample Output :
2
*/

#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int> um;
int solve(int* num,int n,int mn,int* mat){
  if(n<mn){
    return mat[n] = 0;
  }
  if(n==mn){
    return mat[n] = num[mn]*mn;
  }
  if(mat[n]!=-1){
    return mat[n];
  }
  int k = n;
  //int redn1 = n-1; //chosen one
  //int count_k = 0;
  //redn1 = n-1-um[k];
  //cout<<"redn1"<<" "<<redn1<<endl;
  /*while(redn1 >= 0 && num[redn1]==num[n-1]){
    redn1--;
    count_k++;
  }*/
  //int redn2 = redn1 -um[k-1];  //if current is chosen
  /*
  while(redn2>=0 && num[redn2]==num[redn1+1]-1){
    redn2--;
  }
  */
  int option1 = solve(num,n-2,mn,mat);
  int option2 = solve(num,n-1,mn,mat);
  
  if(num[k]*k + option1 >= option2){
    //cout<<"for "<<k;
    mat[n] = num[k]*k + option1;
    //cout<<" "<<mat[n]<<endl;
    return mat[n];
  }
  else{
    //cout<<"for "<<k;
    mat[n] = option2;
    //cout<<" "<<mat[n]<<endl;
    return mat[n];
  } 
}

int main(){
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);

  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    int* num = new int[1005];
    int mx = INT_MIN;
    int mn = INT_MAX;
    int k;
    for(int i=0;i<1005;i++){
      num[i]=0;
    }
    for(int i=0;i<n;i++){
      cin>>k;
      num[k]++;
      if(k>mx){
        mx = k;
      }
      if(k<mn){
		mn = k;
      }
    }
    int* mat = new int[mx+1];
    for(int i=0;i<=mx;i++){
      mat[i]=-1;
    }
    cout<<solve(num,mx,mn,mat)<<endl;
    delete[] num;
    delete[] mat;
  }
  return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;
int solve(int* num,int n,int mn,int* mat){
  if(n<mn){
    return mat[n] = 0;
  }
  if(n==mn){
    return mat[n] = num[mn]*mn;
  }
  if(mat[n]!=-1){
    return mat[n];
  }
  int k = n;
  int option1 = solve(num,n-2,mn,mat);
  int option2 = solve(num,n-1,mn,mat);
  
  if(num[k]*k + option1 >= option2){
    mat[n] = num[k]*k + option1;
    return mat[n];
  }
  else{
    mat[n] = option2;
    return mat[n];
  } 
}

int main(){
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);

  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    int* num = new int[1005];
    int mx = INT_MIN;
    int mn = INT_MAX;
    int k;
    for(int i=0;i<1005;i++){
      num[i]=0;
    }
    for(int i=0;i<n;i++){
      cin>>k;
      num[k]++;
      if(k>mx){
        mx = k;
      }
      if(k<mn){
		mn = k;
      }
    }
    int* mat = new int[mx+1];
    for(int i=0;i<=mx;i++){
      mat[i]=-1;
    }
    cout<<solve(num,mx,mn,mat)<<endl;
    delete[] num;
    delete[] mat;
  }
  return 0;
}
*/