/*
Sehwag has been solving a lot of mathematical problems recently. He was learning ETF (Euler Totient Function) and found the topic quite interesting. So, he tried solving a question on ETF. He will be given two numbers L and R. He has to find the probability that the ETF of a number in the range [L, R] is divisible by a number K.
Input Format:
The first line contains an integer T, representing the number of test cases.
The next T lines will contain three integers L, R and K.
Constraints:
1 <= T <= 10
1 <= L <= R <= 10^12
0 <= R - L <= 10^5
1 <= K <= 10^6
Output Format:
Print the answer in a new line after rounding off the first 6 digits after the decimal place.
Sample Input 1:
3
1 4 2
2 5 2
3 10 4
Sample Output 1:
0.500000
0.750000
0.375000
*/

#include <bits/stdc++.h>
using namespace std;

#define MAX 1100005
typedef long long ll;
bool isPrime[MAX];
vector<ll> primes;
ll phi[MAX];
ll num[MAX];
void seive(){

    for(ll i=0;i<MAX;i++){
        isPrime[i] = true;
    }
    isPrime[0] = false;
    isPrime[1] = false;
    for(ll i=2;i*i<MAX;i++){
        if(isPrime[i]){
            for(ll j=i+i;j<MAX;j+=i){
                isPrime[j] = false;
            }
        }
    }
    for(int i=0;i<MAX;i++){
		if(isPrime[i]){
            primes.push_back(i);
        }
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
	int t;
    cin>>t;
    seive();
    while(t--){
        ll a,b,k;
        cin>>a>>b>>k;
        if(k==1){
            cout<<fixed<<setprecision(6)<<1<<endl;
            continue;
        }
        for(ll i=a;i<=b;i++){
            phi[i-a] = i;
            num[i-a] = i;
        }
        ll sz=primes.size();
        for(ll i=0;primes[i]*primes[i]<=b && i<sz;i++){
            ll y = (a/primes[i]) * primes[i];
            while (y < a)
                y += primes[i];
            while (y < primes[i])
                y += primes[i];
            if(y==primes[i]){
                y +=primes[i];
            }
            for(ll j=y;j<=b;j+=primes[i]){
                while(num[j-a]%primes[i]==0){
                    num[j-a]/=primes[i];
                }
                phi[j-a] -= phi[j-a]/primes[i];
            }
        }
        
        for(ll i=a;i<=b;i++){
			if(num[i-a]>1){
                phi[i-a] -= phi[i-a]/num[i-a];
            }
            num[i-a]=1;
        }
        ll total = 0;
        for(ll i=a;i<=b;i++){
            if(phi[i-a]%k==0){
                total++;
            }
        }
        
        double answer = total;
        answer = answer/(b-a+1);
        cout<<fixed<<setprecision(6)<<answer<<endl;
    }
    return 0;
}