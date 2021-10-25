/*
The fibonacci sequence is defined by the following relation:
 F(0) = 0
 F(1) = 1
 F(N) = F(N - 1) + F(N - 2), N >= 2
Your task is very simple. Given two non-negative integers N and M (N <= M), you have to calculate and return the sum (F(N) + F(N + 1) + ... + F(M)) mod 1000000007.
Input Format :
First line of input will contain T(number of test cases), each test case follows as.
Two non-negative space-separated integers N and M. (N <= M)
Output Format :
A new line containing the answer for the each test case.
Constraints:
1 <= T <= 10^3
1 <= N <= M <= 10^18
Sample Input :
1 
10 19 
Sample Output :
10857
*/

#include<bits/stdc++.h>
using namespace std;

const unsigned int M = 1000000007;

void multiply(long long A[2][2], long long B[2][2]){
    long long mul[2][2];
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            mul[i][j] = 0;
			for(int k=0;k<2;k++){
				mul[i][j] = (mul[i][j]%M + ((A[i][k]%M)*(B[k][j])%M)%M)%M;
            }
        }
    }
    
    for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
            A[i][j] = mul[i][j]; 
        }
    }
}

void getPower(long long M[2][2], long long n){
    if(n==0 || n==1){
        return;
    }
    
    getPower(M,n/2);
    multiply(M,M);
    if(n%2!=0){
        long long T[2][2] = {{1,1},{1,0}};
        multiply(M,T);
    }
}

long long getFibo(long long n){
    long long M[2][2] = {{1,1},{1,0}};
    getPower(M,n-1);
    return 1*M[0][0];
}

int main(){
    
    int t;
    cin>>t;
    while(t--){
        long long n,m;
        cin>>n>>m;
        long long answer1 = getFibo(n+1) - 1;
        long long answer2 = getFibo(m+2) - 1;
        long long answer = (answer2%M - answer1%M + M)%M;
        cout<<answer<<endl;
    }
    return 0;
}

