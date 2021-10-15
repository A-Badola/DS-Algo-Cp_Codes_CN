/*
For a string of n bits x1,x2,x3,...,Xn the adjacent bit count of the string (AdjBC(x)) is given by
X1*X2 + X2*X3 + X3*X4 + ... + Xn-1 * Xn
which counts the number of times a 1 bit is adjacent to another 1 bit. For example:
AdjBC(011101101) = 3
AdjBC(111101101) = 4
AdjBC(010101010) = 0
Write a program which takes as input integers n and k and returns the number of bit strings x of n bits (out of 2ⁿ) that satisfy AdjBC(x) = k. For example, for 5 bit strings, there are 6 ways of getting AdjBC(x) = 2:
11100, 01110, 00111, 10111, 11101, 11011
Input Format:
First-line will contain T(number of the test case).
Each test case consists of a single line containing two space-separated integers N and K, a number of bits in the bit strings and desired adjacent bit count respectively.
Output Format:
For each test case print the answer in a new line.
As answer can be very large print your answer modulo 10^9+7.
Constraints:
1 <= T <= 10^5
1 <= N <= K <= 100
Sample Input
10
5 2
20 8
30 17
40 24
50 37
60 52
70 59
80 73
90 84
100 90
Sample Output
6
63426
1861225
168212501
44874764
160916
22937308
99167
15476
23076518
*/

#include<bits/stdc++.h>
using namespace std;

const unsigned int M = 1000000007;

long long mat[2][101][101];
int numBS(int n, int k, int first){
  
  if(k<0){
      return 0;
  }
    
  if(n==1){
    if(k==0){
      return mat[first][n][k] = 1;
    }
    return mat[first][n][k] = 0;
  }

  if(mat[first][n][k] != -1){
      return mat[first][n][k]%M;
  }
  if(first == 1){
    int p1,p2;
	if(mat[0][n-1][k] != -1){
        p1 = mat[0][n-1][k]%M;
    }
    else{
        mat[0][n-1][k] = numBS(n-1,k,0)%M;
        p1 = mat[0][n-1][k];
    }
    
    if(mat[1][n-1][k-1] != -1){
        p2 = mat[1][n-1][k-1]%M;
    }
    else{
        mat[1][n-1][k-1] = numBS(n-1,k-1,1)%M;
        p2 = mat[1][n-1][k-1];
    }
    return (p1 + p2)%M;
  }
  else{
    int p1,p2;
	if(mat[1][n-1][k] != -1){
        p1 = mat[1][n-1][k]%M;
    }
    else{
        mat[1][n-1][k] = numBS(n-1,k,1)%M;
        p1 = mat[1][n-1][k];
    }
    
    if(mat[0][n-1][k] != -1){
        p2 = mat[0][n-1][k]%M;
    }
    else{
        mat[0][n-1][k] = numBS(n-1,k,0)%M;
        p2 = mat[0][n-1][k];
    }
    return (p1 + p2)%M;
  }
}

int main(){
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);

  int t;
  cin>>t;
  memset(mat,-1,sizeof(mat));
  for(int i=0;i<=1;i++){
      for(int n=1;n<=100;n++){
          for(int k=1;k<=100;k++){
              mat[i][n][k] = numBS(n,k,i)%M;
          }
      }
  }
  while(t--){
    int n,k;
    cin>>n>>k;
    cout<<(numBS(n,k,0)%M + numBS(n,k,1)%M)%M<<endl;
  }
  return 0;
}