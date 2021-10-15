/*
Gary has two string S and V. Now Gary wants to know the length shortest subsequence in S such that it is not a subsequence in V.
Note: input data will be such so there will always be a solution.
Input Format :
Line 1 : String S of length
Line 2 : String V of length
Output Format :
Length of shortest subsequence in S such that it is not a subsequence in V
Constraints:
1 <= |S|, |V| <= 1000
Sample Input :
babab
babba
Sample Output :
3
*/

#include<bits/stdc++.h>
using namespace std;
int mat[1001][1001];
int shortSubs(string s,string v,int m,int n){
  if(m==0){
    return mat[m][n] = 10000000;
  }
  if(n<=0){
    return mat[m][n] = 1;
  }

  if(mat[m][n] != -1){
    return mat[m][n];
  }
  int k; 
  for(k=0; k<n; k++){
    if(v[k]==s[0]){
      break;
    }
  }

  if(k==n){
    return mat[m][n] = 1;
  }

  return mat[m][n] = min(1 + shortSubs(s.substr(1,m-1),v.substr(k+1,n-k-1),m-1,n-k-1), shortSubs(s.substr(1,m-1),v,m-1,n));
}

int main(){
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  memset(mat,-1,sizeof(mat));
  string s1,s2;
  cin>>s1;
  cin>>s2;
  int m = s1.size();
  int n = s2.size();
  cout<<shortSubs(s1,s2,m,n);
  return 0;
}