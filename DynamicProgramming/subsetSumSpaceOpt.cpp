#include<bits/stdc++.h>
using namespace std;

bool sumPossible(int* ar, int n, int k){
  int** mat = new int* [2];
  for(int i=0;i<=1;i++){
    mat[i] = new int[k+1];
  }

  for(int i=0;i<=k;i++){
    mat[0][i] = false;
  }
  mat[0][0] = true;
  mat[1][0] = true;
  int flag = 1;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=k;j++){
      if(j-ar[i-1]>=0){
        mat[flag][j] = mat[flag^1][j-ar[i-1]] || mat[flag^1][j];
      } else {
        mat[flag][j] = mat[flag^1][j];
      }
    }
    flag = flag^1;
  }

  return mat[flag^1][k];
}

int main(){
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);

  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    int* ar = new int[n];
    for(int i=0;i<n;i++){
      cin>>ar[i];
    }
    int k;
    cin>>k;

    if(sumPossible(ar,n,k)){
      cout<<"Yes"<<endl;
    } else {
      cout<<"No"<<endl;
    }
  }
  return 0;
}
