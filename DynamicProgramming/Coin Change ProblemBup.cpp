//<R>
/*
You are given an infinite supply of coins of each of denominations D = {D0, D1, D2, D3, ...... Dn-1}. You need to figure out the total number of ways W, in which you can make a change for Value V using coins of denominations D.
Note : Return 0, if change isn't possible.
W can be pretty large so output the answer % mod(10^9 + 7)
Input Format
First line will contain T (number of test case), each test case is consists of 3 three lines.
Line 1 : Integer n i.e. total number of denominations
Line 2 : N integers i.e. n denomination values
Line 3 : Value V
Output Format
For each test case print the number of ways (W) % mod(10^9 +7) in new line.
Constraints :
1 <= T <= 10
1 <= N <= 10
1 <= V <= 5000

*/

#include<bits/stdc++.h>
using namespace std;

const unsigned int M = 1000000007;
long long numWays(int coin[],int n,int val){
    long long mat[n+1][val+1];
    for(int i=0;i<=val;i++){
        mat[0][i]=0;
    }
    for(int i=0;i<=n;i++){
        mat[i][0]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=val;j++){
			mat[i][j] = 0;
            if(j-coin[i-1]>=0){
                mat[i][j] = mat[i][j-coin[i-1]]%M;
            }
            mat[i][j] += mat[i-1][j]%M;
        }
    }
    return mat[n][val]%M;
}
int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int coin[n];
        for(int i=0;i<n;i++){
			cin>>coin[i];
        }
        int val;
        cin>>val;
        cout<<numWays(coin,n,val)<<endl;
    }
    return 0;
}