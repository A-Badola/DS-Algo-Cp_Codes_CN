//R
/*
A child is running up a staircase with n steps and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count how many possible ways the child can run up to the stairs. You need to return all possible number of ways.
Time complexity of your code should be O(n).
Since the answer can be pretty large print the answer % mod(10^9 +7)
Input Format:
First line will contain T (number of test case).
Each test case is consists of a single line containing an integer N.
Output Format:
For each test case print the answer in new line
Constraints :
1 <= T < = 10
1 <= N <= 10^5

*/

#include<bits/stdc++.h>
using namespace std;

const unsigned int M = 1000000007;

long long numWays(int n,long long* mat){
  if(n==1){
    return mat[n] = 1;
  }
  if(n==2){
    return mat[n] = 2;
  }
  if(n==3){
    return mat[n] = 4;
  }
  if(mat[n]!=-1){
      return mat[n];
  }
  return mat[n] = (numWays(n-1,mat)%M + numWays(n-2,mat)%M + numWays(n-3,mat)%M)%M; 
}

int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    long long mat[n+1];
    memset(mat,-1,sizeof(mat));
    cout<<numWays(n,mat)<<endl;
  }
  return 0;
}