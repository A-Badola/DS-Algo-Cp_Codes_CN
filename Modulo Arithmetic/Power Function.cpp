/*
You are given two integers, X and Y. You have to compute X^Y.
Example:
2^3 evaluates to 8.
Since the result can be large, so calculate the X^Y % M, where M is 10^9 + 7.
Note: Apply the brute force method to solve the problem.
Input Format:
The first line of input contains an integer, that denotes the value of the number of test cases. Let us denote it with the symbol T.
Each test case consists of two space separated integers, that denote the value of X and Y. Each test case is given in a separate line.
Output Format:
For each test case, print the answer modulo 10^9 + 7 in a separate line.
Constraints:
1 <= T <= 50
1 <= X, Y <= 10^5
Time Limit: 1 second
Sample Input 1:
2
2 3
3 2
Sample Output 1:
8
9
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const unsigned int M = 1000000007;

ll modpow(int x,int y){
    if(y==0){
        return 1;
    }
    ll xn;
    if(y%2==0){
        xn = modpow(x,y/2);
        return ((xn%M)*(xn%M))%M;
    }
    else{
        xn = modpow(x,y-1);
        return ((x%M)*(xn%M))%M;
    }
}

int main(){
    
	int t;
    cin>>t;
    while(t--){
        int x,y;
        cin>>x>>y;
        cout<<modpow(x,y)<<endl;
    }
    return 0;
}

