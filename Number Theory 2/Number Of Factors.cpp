/*
Number Of Factors
A number is called n-factorful if it has exactly n distinct prime factors. Given positive integers a, b, and n, your task is to find the number of integers between a and b, inclusive, that are n-factorful. We consider 1 to be 0-factorful.
Input Format:
First line of input will contain T(number of test cases), each test case follows as.
Each test cases consists of a single line containing integers a, b, and n as described above.
Output Format:
Output for each test case one line containing the number of n-factorful integers in [a, b].
Constraints:
1 <= T <= 10000
1 ≤ a ≤ b ≤ 10^6
0 <= b - a <= 100
0 ≤ n ≤ 10
Sample Input
4
1 3 1
1 10 2
1 10 3
1 100 3
Sample Output
2 
2
0
8
*/

#include<bits/stdc++.h>
using namespace std;

#define MAX 1000001
typedef long long ll;

int f[MAX];
void factNum(){
  memset(f,0,sizeof(f));
  for(int i=2; i<MAX; i++){
    if(f[i]==0){
      f[i] = 2;
      for(int j=i+i;j<MAX;j+=i){
        f[j]++;
      }
    }
  }

  //for(int i=0;i<=40;i++){
   // cout<<f[i]<<" ";
  //}
  //cout<<endl<<endl;
}



int main(){
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  
  factNum();
  int t;
  cin>>t;
  while(t--){
    int a,b,n;
    cin>>a>>b>>n;
    int ans =0;
    for(int i = a; i <= b; i++){
        if(f[i] == n){
            ans++;
        }
    }
    cout << ans << endl;
  }
  return 0;
}

// efficient 2

#include<bits/stdc++.h>
using namespace std;

#define MAX 1000001
typedef long long ll;

int f[MAX];
int mat[11][1000001];
void factNum(){
  memset(f,0,sizeof(f));
  for(int i=2; i<MAX; i++){
    if(f[i]==0){
      f[i] = 2;
      for(int j=i+i;j<MAX;j+=i){
        f[j]++;
      }
    }
  }

  //for(int i=0;i<=40;i++){
   // cout<<f[i]<<" ";
  //}
  //cout<<endl<<endl;
  memset(mat,0,sizeof(mat));


  for(int i=0;i<=10;i++){
    for(int j=1;j<MAX;j++){
      if(f[j]==i){
        mat[i][j] = 1 + mat[i][j-1];
      }
      else
      {
        mat[i][j] = mat[i][j-1];
      }
    }
  }
/*
  for(int i=1;i<=10;i++){
    for(int j=1;j<=40;j++){
      cout<<mat[i][j]<<" ";
    }
    cout<<endl;
  }
  */
}



int main(){
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  
  factNum();
  int t;
  cin>>t;
  while(t--){
    int a,b,n;
    cin>>a>>b>>n;
    cout<<mat[n][b] - mat[n][a-1]<<endl;
  }
  return 0;
}