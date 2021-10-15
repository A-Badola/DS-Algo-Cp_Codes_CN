/*
You just received another bill which you cannot pay because you lack the money.
Unfortunately, this is not the first time to happen, and now you decide to investigate the cause of your constant monetary shortness. The reason is quite obvious: the lion's share of your money routinely disappears at the entrance of party localities.
You make up your mind to solve the problem where it arises, namely at the parties themselves. You introduce a limit for your party budget and try to have the most possible fun with regard to this limit.
You inquire beforehand about the entrance fee to each party and estimate how much fun you might have there. The list is readily compiled, but how do you actually pick the parties that give you the most fun and do not exceed your budget?
Write a program which finds this optimal set of parties that offer the most fun. Keep in mind that your budget need not necessarily be reached exactly. Achieve the highest possible fun level, and do not spend more money than is absolutely necessary.
Input Format:
First line of input will contain an integer N (number of parties).
Next line of input will contain N space-separated integers denoting the entry fee of Ith party.
Next line will contain N space-separated integers denoting the amount of fun Ith party provide.
Last line of input will contain an integer W party budget.
Output Format:
For each test case your program must output the sum of the entrance fees and the sum of all fun values of an optimal solution. Both numbers must be separated by a single space. 
Note: In case of multiple cost provides the maximum fun output the minimum total cost.
Sample Input:
5
1 7 9 7 2 
5 5 2 4 7 
12
Sample Output:
10 17
*/

#include<bits/stdc++.h>
using namespace std;

int mfun(int price[],int fun[],int n,int W){
  int** mat = new int*[n+1];
  for(int i=0;i<=n;i++){
    mat[i] = new int[W+1]; 
  }
  for(int i=0; i<=n; i++){
    mat[i][0] = 0;
  }
  for(int i=0;i<=W;i++){
    mat[0][i] = 0;
  }
  for(int i=1; i<=n; i++){
    for(int j=1; j<=W; j++){
      if(j - price[i-1]>=0){
        mat[i][j] = max(fun[i-1] + mat[i-1][j-price[i-1]],mat[i-1][j]);
      }
      else{
        mat[i][j] = mat[i-1][j];
      }
    }
  }
  //for(int i=0;i<=n;i++){
    //for(int j=0;j<=W;j++){
      //cout<<setw(4)<<mat[i][j]<<" ";
    //}
    //cout<<endl;
  //}
  int ans = mat[n][W];
  for(int i=0;i<n;i++){
    delete[] mat[i];
  }
  delete[] mat;
  return ans;
}

int minPrice(int fun[],int price[],int n,int mxfun){
  /*
  if(mxfun==0){
    return 0;
  }
  if(n==0){
    return 100000;
  }

  if(mxfun - fun[n-1]>=0){
    return min(price[n-1] + minPrice(fun,price,n-1,mxfun-fun[n-1]),minPrice(fun,price,n-1,mxfun));
  }
  else{
    return minPrice(fun,price,n-1,mxfun);
  }
  */

  int** mat = new int*[n+1];
  for(int i=0;i<=n;i++){
    mat[i] = new int[mxfun+1];
  }
  for(int i=0;i<=n;i++){
    mat[i][0] = 0;
  }
  for(int i=1;i<=mxfun;i++){
    mat[0][i] = 100000;
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=mxfun;j++){
      if(j - fun[i-1]>=0){
        mat[i][j] = min(price[i-1] + mat[i-1][j-fun[i-1]],mat[i-1][j]);
      }
      else{
        mat[i][j] = mat[i-1][j];
      }
    }
  }
  int ans = mat[n][mxfun];
  for(int i=0;i<n;i++){
    delete[] mat[i];
  }
  delete[] mat;
  return ans;
}
int main(){
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);

  int n;
  cin>>n;
  int price[n];
  for(int i=0;i<n;i++){
    cin>>price[i];
  }
  int fun[n];
  for(int i=0;i<n;i++){
    cin>>fun[i];
  }
  int W;
  cin>>W;
  int mxFun = mfun(price,fun,n,W);
  int minP = minPrice(fun,price,n,mxFun);
  cout<<minP<<" "<<mxFun<<endl;
  return 0;
}