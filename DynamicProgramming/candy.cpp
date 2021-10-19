/*
Gary is a teacher at XYZ school. To reward his N students he bought a packet of N candies all with different flavours. But the problem is some students like certain flavour while some doesn't. Now Gary wants to know the number of ways he can distribute these N candies to his N students such that every student gets exactly one candy he likes.
Input Format :
The first line of input will contain T(number of test cases), each test case follows as.
Line 1 : An integer N (1<= N <= 16) denoting number of students and candies.
Next N lines: N integers describing the preferences of one student. 1 at i'th (0 <= i < N) position denotes that this student likes i'th candy, 0 means he doesn't.
Assume input to be 0-indexed based.
Output Format :
Return the number of ways Gary can distribute these N candies to his N students such that every student gets exactly one candy he likes for each test case in a new line.
Sample Input:
1
3
1 1 1
1 1 1
1 1 1
Sample Output:
6
Explanation:
Since, all the students like all the candies, so, the candies can be distributed in the following 6 ways:

*/

#include<bits/stdc++.h>
using namespace std;

long long numWays(int fav[][16], int n,int s, int mask, long long* mat){
  if(s>n){
      return mat[mask] = 0;
  }
  
  if(mask == (1<<n) - 1){
    return mat[mask] = 1;
  }
    
  if(mat[mask]!=-1){
    return mat[mask];
  }
    
  long long ways = 0;
  for(int j=0; j<n; j++){
    if(fav[s][j] && !(mask & (1<<j))){
      ways = ways + numWays(fav,n,s+1,mask|(1<<j),mat);
    }
  }
  mat[mask] = ways;
  return ways;
}

int main(){
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);

  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    int fav[16][16];
    memset(fav,0,sizeof(fav));
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        cin>>fav[i][j];
      }
    }
    long long* mat = new long long[(1<<n)];
    for(int i=0;i<(1<<n);i++){
      mat[i] = -1;
    }
    long long ans = numWays(fav,n,0,0,mat);
    cout<<ans<<endl;
    
  }
  return 0;
}