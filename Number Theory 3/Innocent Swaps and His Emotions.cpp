/*
There are only three phases in Swaps life: Sleep, Play and Study. Also, there are two types of emotions Swaps experiences: Happy and Sad. Each phase of his life brings either kind of emotions.
The sleep and the play phase makes Swaps happy whereas the study phase makes him sad. Quite obvious, isn't it? But we know that life isn't that great, one cannot be happy all the time.
Swaps, being a very sensitive guy, doesn't like to mix his emotions on a particular day. So each day, he is in exactly one of the three phases.
Given N which denotes the number of days and K which denotes the exact number of days Swaps needs to be happy out of these N days, can you tell him in how many ways can he achieve this? Since the output value can be very large, take modulo with 1000000007(10^9+7)
Input Format:
The first line of the input contains T, denoting the number of test cases.

The next T lines contain two space-separated integers N and K.
Constraints:
1 <=T <= 10^5
1<= K <= N <= 10^6
Output Format:
For each test-case, output a single integer, the number of ways modulo 1000000007(10^9+7).
Sample Input 1:
3
1 1
2 1
3 2
Sample Output 2:
2
4
12
Explanation
In the first test case, he needs to feel joyful on Day 1. Hence, answer is 2 (He can either play video games or sleep).

In the second test case, he can be joyful either on Day 1 or Day 2. So number of ways = 4.
*/

#include<bits/stdc++.h>
using namespace std;
const unsigned long long M = 1000000007;
typedef long long ll;

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

ll fact(ll* f,ll a){
	ll res=f[a-1];
	res=(res%M * a%M)%M;
	return res;
}

int main(){
    
    int t;
    cin>>t;
    ll f[1000005];
    f[0] = 1;
    for(int j=1;j<=1000002;j++){
        f[j] = fact(f,j);
    }
    while(t--){
        int n,k;
        cin>>n>>k;
        ll answer = 1;
        ll op1 = power(2,k)%M;
        answer = (answer*op1)%M;
        ll op2 = f[n]%M;
        answer = (answer*op2)%M;
        ll op4 = power(f[k],M-2)%M;
        answer = (answer*op4)%M;
        ll op3 = power(f[n-k],M-2)%M;
        answer = (answer*op3)%M;
        cout<<answer<<endl;
    }
    return 0;
}