/*
A thief robbing a store and can carry a maximal weight of W into his knapsack. There are N items and ith item weigh wi and is of value vi. What is the maximum value V, that thief can take ?
Note: Space complexity should be O(W).
Input Format :
Line 1 : N i.e. number of items
Line 2 : N Integers i.e. weights of items separated by space
Line 3 : N Integers i.e. values of items separated by space
Line 4 : Integer W i.e. maximum weight thief can carry
Output Format :
Line 1 : Maximum value V
Constraints
1 <= N <= 10^4
1<= wi <= 100
1 <= vi <= 100
1 <= W <= 1000
Sample Input 1 :
4
1 2 4 5
5 4 8 6
5
Sample Output :
13
*/

#include<bits/stdc++.h>
using namespace std;
/*
int knap(int w[],int val[],int n,int W,int** mat){
  if(n==0 || W==0){
    return mat[n][W] = 0;
  }

  if(mat[n][W]!=-1){
    return mat[n][W];
  }

  if(W - w[n-1]>=0){
    return mat[n][W] = max(val[n-1]+knap(w,val,n-1,W - w[n-1],mat),knap(w,val,n-1,W,mat));
  }
  else{
    return mat[n][W] = knap(w,val,n-1,W,mat);
  }
}
*/

int knap(int w[],int val[],int n,int W,int** mat){
  for(int i=0;i<=n;i++){
    mat[i][0] = 0;
  }
  for(int i=0;i<=W;i++){
    mat[0][i] = 0;
  }

  for(int i=1;i<=n;i++){
    for(int j=1;j<=W;j++){
      if(j - w[i-1]>=0){
        mat[i][j] = max(val[i-1] + mat[i-1][j-w[i-1]],mat[i-1][j]);
      }
      else{
        mat[i][j] = mat[i-1][j];
      }
    }
  }

  return mat[n][W];
}
int main(){
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);

  int n;
  cin>>n;
  int w[n];
  for(int i=0;i<n;i++){
    cin>>w[i];
  }
  int val[n];
  for(int i=0;i<n;i++){
    cin>>val[i];
  }
  int W;
  cin>>W;
  int** mat = new int* [n+1];
  for(int i=0;i<=n;i++){
    mat[i] = new int[W+1];
  }
  cout<<knap(w,val,n,W,mat);
  return 0;
}