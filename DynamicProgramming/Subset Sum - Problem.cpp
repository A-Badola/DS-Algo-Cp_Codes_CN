/*
Given an array of n integers, find if a subset of sum k can be formed from the given set. Print Yes or No.
Input Format
First-line will contain T(number of test cases), each test case consists of three lines. 
First-line contains a single integer N(length of input array).
Second-line contains n space-separated integers denoting the elements of array.
The last line contains a single positive integer k.
Output Format
Output Yes if there exists a subset whose sum is k, else output No for each test case in new line.
Constraints:
1 <= T <= 100
1 <= N <= 500
1 <= arr[i] <= 10^4
1 <= K <= 500
Sample Input
1
3
1 2 3
4
Sample Output
Yes
*/

#include<bits/stdc++.h>
using namespace std;

bool sumPossible(int* ar, int** mat, int n, int k){
  if(k==0){
    return mat[n][k] =  1;
  }
  if(n==0){
    return mat[n][k] = 0;
  }
  if(mat[n][k] != -1){
    return mat[n][k];
  }
  if(k-ar[n-1]>=0){
    return mat[n][k] = sumPossible(ar,mat,n-1,k-ar[n-1]) || sumPossible(ar,mat,n-1,k);
  } else {
    return mat[n][k] = sumPossible(ar,mat,n-1,k);
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

    int* ar = new int[n];
    for(int i=0; i<n; i++){
      cin>>ar[i];
    }
    int k;
    cin>>k;
    int** mat = new int*[n+1];
    for(int i=0; i<=n; i++){
      mat[i] = new int[k+1];
    }
    for(int i=0;i<=n;i++){
      for(int j=0;j<=k;j++){
        mat[i][j] = -1;
      }
    }
    if(sumPossible(ar,mat,n,k)){
      cout<<"Yes"<<endl;
    } else {
      cout<<"No"<<endl;
    }
    delete[] ar;
    for(int i=0;i<=n;i++){
      delete[] mat[i];
    }
    delete[] mat;
  }
  return 0;
}