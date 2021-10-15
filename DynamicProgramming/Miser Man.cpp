/*
Jack is a wise and miser man. Always tries to save his money. 
One day, he wants to go from city A to city B. Between A and B, there are N number of cities(including B and excluding A) and in each city there are M buses numbered from 1 to M. And the fare of each bus is different. Means for all N*M busses, fare (K) may be different or same. Now Jack has to go from city A to city B following these conditions:
1. At every city, he has to change the bus.
2. And he can switch to only those buses which have number either equal or 1 less or 1 greater to the previous.
You are to help Jack to go from A to B by spending the minimum amount of money.
Input Format:
First-line will contain T(number of the test case), each test case follows as.
First-line will contain two space-separated integers N and M.
Next, N rows will contain M space-separated integers denoting the elements of the grid.
Each row lists the fares the M busses to go form the current city to the next city.
Output Format:
For each test case print the minimum amount of fare that Jack has to give in a newline.
Constraints:
1 <= T <= 100
1 <= N, M <= 100
1 <= arr[i][j] <= 10^5
Sample Input
1
5 5
1 3 1 2 6
10 2 5 4 15
10 9 6 7 1
2 7 1 5 3
8 2 6 1 9
Sample Output
10
Explanation:
1 -> 4 -> 1 -> 3 -> 1: 10
This is marked and shown in the following image: 
*/

#include<bits/stdc++.h>
using namespace std;

int mat[150][150];
int route_find(int** price,int n,int m,int i){
  if(n==0){
    return 0;
  }
  if(mat[n][i] != -1){
      return mat[n][i];
  }
  if(i==0){
    return mat[n][i] = min(price[n-1][i] + route_find(price,n-1,m,i),price[n-1][i+1] + route_find(price,n-1,m,i+1));
  }else if(i==m-1){
    return mat[n][i] = min(price[n-1][i] + route_find(price,n-1,m,i),price[n-1][i-1] + route_find(price,n-1,m,i-1));
  }else{
    return mat[n][i] = min(price[n-1][i] + route_find(price,n-1,m,i),min(price[n-1][i-1] + route_find(price,n-1,m,i-1),price[n-1][i+1] + route_find(price,n-1,m,i+1)));
  }
}

int route(int** price,int n,int m){
  int min_amount = INT_MAX;
  int amount ;
  for(int i=0;i<m;i++){
    amount = price[n-1][i] + route_find(price,n-1,m,i);
    //cout<<i<<" "<<amount<<endl;
    if(amount<min_amount){
      min_amount = amount;
    }
  }
  return min_amount;
}

int main(){
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);

  int t;
  cin>>t;
  while(t--){
    memset(mat,-1,sizeof(mat));
    int n,m;
    cin>>n>>m;
    int** price = new int*[n];
    for(int i=0;i<n;i++){
      price[i] = new int[m];
    }
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        cin>>price[i][j];
      }
    }
    cout<<route(price,n,m)<<endl;    
    for(int i=0;i<n;i++){
      delete[] price[i];
    }
    delete[] price;
  }
  return 0;
}

