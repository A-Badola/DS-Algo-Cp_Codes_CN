/*
Given a number N, find number of primes in the range [1,N].
Input Format:
The only line of input consists of a number N
Output Format:
Print the number of primes in the range [1,N].
Constraints:
1 ≤ N ≤ 10^6
Sample Input :
3 
Sample Output -
2
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    bool ar[n+1];
    for(int i=0;i<=n;i++){
        ar[i] = true;
    }
    ar[0] = false;
    ar[1] = false;
    for(int i=2;i*i<=n;i++){
        if(ar[i]){
            for(int j=i*i;j<=n;j+=i){
                ar[j] = false;
            }
        }
    }
    int cnt = 0;
    for(int i=0;i<=n;i++){
        if(ar[i]){
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}