/*
Special Prime is a prime number that can be written as the sum of two neighbouring primes and 1.
You are given an integer N and you are supposed to find the number special prime in the range: [1, N].
Example of special prime 19 = 7 + 11 + 1
Neighbouring primes are prime number such that there is no other prime number between them.
Input Format:
An integer N.
Output Format:
Print the number of special primes
Constraints:
1 <= N <= 2*10^5
Sample Input:
27
Sample Output:
2
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    
    // write your code here
    long long n;
    cin>>n;
    bool a[n+1];
    memset(a,true,sizeof(a));
    a[0] = false;
    a[1] = false;
    for(long long i=2;i<=n;i++){
		if(a[i]){
            for(long long j=i*i; j<=n; j+=i){
                a[j] = false;
            }
        }
    }
    long long val=0;
    long long prev = 2;
    for(long long i=3;i<=n;i++){
        if(a[i]){
            long long k = i + prev + 1;
            if(k<=n){
                if(a[k]){
                    val++;
                }
            }
            prev = i;
        }
    }
    cout<<val;
    return 0;
}