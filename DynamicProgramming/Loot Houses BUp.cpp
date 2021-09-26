//<R>
/*

#include<bits/stdc++.h>
using namespace std;

long long max_loot(int* money,int n,int* mat){
  if(n<1){
    return 0;
  }
  if(n==1){
    return mat[n-1]=money[n-1];
  }
  if(mat[n-1]!=-1){
      return mat[n-1];
  }
  long long option1 = max_loot(money,n-2,mat);
  long long option2 = max_loot(money,n-1,mat);
  return mat[n-1] = max(option1 + money[n-1],option2);
}
int main(){
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);

  int n;
  cin>>n;
  int* money = new int[n];
  for(int i=0;i<n;i++){
    cin>>money[i];
  }
  int *mat = new int[n];
  for(int i=0;i<n;i++){
  mat[i] = -1;
  }
  long long one = max_loot(money,n,mat);
  cout<< one;
  return 0;
}
*/


#include<bits/stdc++.h>
using namespace std;

long long max_loot(int* money,int n){
  long long* mat = new long long[n];
  mat[0]=money[0];
  mat[1]=money[1];
  mat[2]=money[2]+money[0];
  for(int i=3;i<n;i++){
    mat[i] = max(money[i]+mat[i-2],money[i]+mat[i-3]);
  }
  long long opt1 = mat[n-1];
  long long opt2 = mat[n-2];
  delete[] mat;
  return max(opt1,opt2);
}
int main(){
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);

  int n;
  cin>>n;
  int* money = new int[n];
  for(int i=0;i<n;i++){
    cin>>money[i];
  }
  cout<<max_loot(money,n);
  delete[] money;
  return 0;
}