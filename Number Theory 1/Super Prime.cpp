/*
A number is called super-prime if it has exactly two distinct prime divisors
Example 10 , 6
You are supposed to find the count of super-prime numbers between 1 and N (inclusive).
Input Format:
Contain an integer N
Output Format:
Print the number of super prime between [1, N]
Constraints:
1 <= N <= 10^6
Sample Input 1:
10
Sample Output 1:
2
Sample Input 2:
25
Sample Output 2:
10
Explanation:
The super-primes are: 6, 10, 12, 14, 15, 18, 20, 21, 22, 24.
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    // write your code here
    int n;
    cin>>n;
    
    int a[n+1];
    memset(a,0,sizeof(a));
    for(int i=2;i<=n;i++){
        if(!a[i]){
            for(int j=i+i; j<=n; j+=i){
                a[j]++;
            }
        }
    }
    
    int ans = 0;
    
    for(int i=1;i<=n;i++){
        //cout<<a[i]<<" ";
        if(a[i]==2){
            ans++;
        }
    }
    //cout<<endl;
    cout<<ans;
    
    return 0;
}