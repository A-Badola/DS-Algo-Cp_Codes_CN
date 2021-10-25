/*
Daulat Ram is an affluent business man. After demonetization, IT raid was held at his accommodation in which all his money was seized. He is very eager to gain his money back, he started investing in certain ventures and earned out of them. On the first day, his income was Rs. X, followed by Rs. Y on the second day. Daulat Ram observed his growth as a function and wanted to calculate his income on the Nth day.
The function he found out was FN = FN-1 + FN-2 + FN-1×FN-2
Given his income on day 0 and day 1, calculate his income on the Nth day (yeah Its that simple).
Input Format:
The first line of input consists of a single integer T denoting the number of test cases.
Each of the next T lines consists of three integers F0, F1 and N respectively.
Output Format:
For each test case, print a single integer FN, as the output can be large, calculate the answer modulo 10^9+7.
Constraints:
1 ≤ T ≤ 10^5
0 ≤ F0, F1, N ≤ 10^9
Sample Input :
2
0 1 2
1 2 4
Sample Output:
1
107
Explanation
In the second test case his income on day 0 is 1 and the income on day 1 is 2. We need to calculate his income on day 4.

F0=1

F1=2

F2=1 + 2 + 1×2 = 5

F3=2 + 5 + 2×5 = 17

F4=5 + 17 + 5×17 = 107
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const unsigned int M = 1000000007;
const unsigned int Mn = 1000000006;

ll power(ll x, ll n) {
    if(n==0){
        return 1;
    }
    if(n==1){
        return x;
    }
	ll temp;
    ll ans;
    if(n%2==0){
        temp=power(x,n/2);
    	ans = ((temp%M)*(temp%M))%M;
    }
    else{
        temp=((x%M)*(power(x,n-1)%M))%M;
        ans = temp;
    }
    return ans;
}


void multiply(ll A[2][2], ll B[2][2]){
  ll Mul[2][2];
  for(int i=0;i<2;i++){
    for(int j=0;j<2;j++){
      Mul[i][j] = 0;
      for(int k=0;k<2;k++){
        Mul[i][j] = (Mul[i][j]%Mn + ((A[i][k]%Mn)*(B[k][j]%Mn))%Mn)%Mn;
      }
    }
  }

  for(int i=0;i<2;i++){
    for(int j=0;j<2;j++){
      A[i][j] = Mul[i][j]%Mn;
    }
  }
}

void getPower(ll M[2][2], ll n){
  if(n==0 || n==1){
    return;
  }

  getPower(M,n/2);
  multiply(M,M);

  if(n%2!=0){
    ll T[2][2] = {{1,1},{1,0}};
    multiply(M,T);
  }
}

ll nthfibo(ll n){
  ll M[2][2] = {{1,1},{1,0}};
  getPower(M,n-1);
  return 1*M[0][0];
}


ll income(ll f0, ll f1, ll n){
    ll g0 = 1 + f0;
    ll g1 = 1 + f1;
    ll x = nthfibo(n-1)%Mn;
    ll p1 = power(g0,x);
    ll y = nthfibo(n)%Mn;
    ll p2 = power(g1,y);
    ll ans = ((p1%M)*(p2%M))%M;
	ans = ans - 1;
    return ans;
}


int main(){
    int t;
    cin>>t;
    while(t--){
        ll f0,f1,n;
        cin>>f0>>f1>>n;
        ll answer = income(f0,f1,n);
        cout<<answer<<endl;
    }
    return 0;
}