/*
Counting Strings
Given a string 's' consisting of upper case alphabets, i.e. from 'A' to 'Z'. Your task is to find how many strings 't' with length equal to that of 's', also consisting of upper case alphabets are there satisfying the following conditions:
-> String 't' is lexicographical larger than string 's'.
-> When you write both 's' and 't' in the reverse order, 't' is still lexicographical larger than 's'.
Find out number of such strings 't'. As the answer could be very large, take modulo 10^9 + 7.
Input Format:
First line will contain T(number of test cases).
Each test case consists of a single line containing the string s.
Output Format:
For each test case output the number of strings (t) %(10^9 + 7) in new line.
Constraints:
1 <= T <= 50
1 <= |S| <= 10^5
Sample Input:
2
A
XKS
Sample output:
25
523
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const unsigned int md = 1000000007;
typedef vector<ll> vi;
/*
int mat[100001][2][2];
string s;
int n;

ll countString(int*** mat,int ind,int left,int right){

  if(ind==n && left && right){
    return 1;
  }
  if(ind>=n){
    return 0;
  }
	
  if(mat[ind][left][right]!=-1){
      return mat[ind][left][right];
  }
    
  ll ans = 0;
  if(left==0){
    for(int i=s[ind];i<='Z';i++){
      
      if(s[ind] < i){
        ans = (ans + countString(mat,ind+1,1,1))%M;
      }
      if(s[ind]==i){
        ans = (ans + countString(mat,ind+1,0,right))%M;
      }
    }

  }
  else{
    for(int i='A';i<='Z';i++){
      if(s[ind]<i){
        ans = (ans + countString(mat,ind+1,1,1))%M;
      }
      else if(s[ind]>i){
        ans = (ans + countString(mat,ind+1,1,0))%M;
      }
      else{
        ans = (ans + countString(mat,ind+1,1,right))%M;
      }
    }
  }

  return mat[ind][left][right] = ans%M;
}
*/
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);

  int t;
  cin>>t;
  while(t--){
    /*
      memset(mat,-1,sizeof(mat));
    cin>>s;
    n = s.size();
    int*** mat = new int** [n+1];
    for(int i=0;i<=n;i++){
        mat[i] = new int*[2];
        for(int j=0;j<2;j++){
            mat[i][j] = new int[2];
            for(int k=0;k<2;k++){
                mat[i][j][k]=-1;
            }
        }
    }
    cout<<countString(mat,0,0,0)<<endl;*/
    string s;
    cin>>s;
	int n=s.size();
	vi v(n);
	ll ans=0;
	for(int i=0;i<n;i++){
		v[i]='Z'-s[i];
		ans+=v[i];
	}

	ll so=0;
	vi cum(n);
	for(int i=n-1;i>=0;i--){
		so+=v[i];
		cum[i]=so;
		so*=26;
		so%=md;
	}
	for(int i=0;i<n-1;i++){
		ans= (ans + ((v[i]%md)*(cum[i+1]%md))%md)%md;
	}
	ans%=md;
	ans+=md;ans%=md;
	cout<<ans<<endl;
  }
  return 0;
}