/*
Given a string, count the number of distinct subsequences of it ( including empty subsequence ). For the uninformed, A subsequence of a string is a new string which is formed from the original string by deleting some of the characters without disturbing the relative positions of the remaining characters.
For example, "AGH" is a subsequence of "ABCDEFGH" while "AHG" is not.
Input Format:
First line of input contains an integer T which is equal to the number of test cases.
Each of next T lines contains a string s.
Output Format:
Output consists of T lines. Ith line in the output corresponds to the number of distinct subsequences of ith input string. Since, this number could be very large, you need to output ans%(10^9 + 7) where ans is the number of distinct subsequences. 
Constraints:
T ≤ 100
1 <= length(S) ≤ 10^5
All input strings shall contain only uppercase letters.

*/

#include<bits/stdc++.h>
using namespace std;

const unsigned int M = 1000000007;

int distinctSubs(string s, int n){	
    int mat[n+1];
    int ch[256];
    memset(ch,-1,sizeof(ch));
    mat[0] = 1;
    for(int i=1;i<=n;i++){
        if(ch[s[i-1]]!=-1){
            mat[i] =(2*(mat[i-1])%M - (mat[ch[s[i-1]]])%M + M)%M;
        }
        else{
            mat[i] = 2*(mat[i-1]%M);
        }
        ch[s[i-1]] = i - 1;
    }
    //for(int i=0;i<n;i++){
    //  cout<<mat[i]<<" ";
    //}
    //cout<<endl;
    return mat[n]%M;   
}
/*
int ar[100005];
int distinctSubs(string s, int n){
  if(n==0){
    return ar[0] = 1;
  }
  
  int val = distinctSubs(s,n-1);
  int rep;
  if(mp[s[n-1]]==0){
    rep = 0;
  }
  else{
    rep = ar[mp[s[n-1]]];
  }
  //cout<<n<<" "<<rep<<endl;
  int ans = 2*val - rep;
  mp[s[n-1]] = n;
  return ar[n] = ans;
}
*/
int main(){
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);

  int t;
  cin>>t;
  while(t--){
    string s;
    cin>>s;
    //cout<<s<<endl;
    int n = s.size();
    cout<<distinctSubs(s,n)<<endl;
  }
  return 0;
}

