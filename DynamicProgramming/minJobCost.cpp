 #include<bits/stdc++.h>
using namespace std;

int minCost(int cost[4][4], int n, int p, int mask, int* mat){
  if(p>=n){
    return 0;
  }

  if(mat[mask]!=INT_MAX){
    return mat[mask];
  }

  int minimum = INT_MAX;
  for(int j=0;j<n;j++){
    if(!(mask & (1<<j))){
      int ans = minCost(cost,n,p+1, mask | (1<<j),mat) + cost[p][j];
      if(minimum > ans){
        minimum = ans;
      }
    }
  }
  mat[mask] = minimum;
  return minimum;
}

int main(){
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);

  int cost[4][4] = {{10,2,6,5},{1,15,12,8},{7,8,9,3},{15,13,4,10}};
  int* mat = new int[1<<4];
  for(int i=0;i<(1<<4);i++){
    mat[i] = INT_MAX; 
  }
  cout<<minCost(cost,4,0,0,mat)<<endl;
  cout<<mat[0]<<endl;
  return 0;
}