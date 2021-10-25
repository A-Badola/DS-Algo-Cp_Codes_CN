/*
Given the value of N, you will have to find the value of G. The meaning of G is given in the following code
G=0;
for(i = 1 ; i < N ; i++)
   for(j = i+1 ; j <= N ; j++) 
       G+=gcd(i,j);
Here gcd() is a function that finds the greatest common divisor of the two input numbers.
Input Format:
The first line of input will contain T(number of the test case). Each test case contains an integer N.
Output Format:
For each test case print the answer in a new line.
Constraints:
1 <= T <= 10^5
1 <= N <= 10^5
Sample Input:
3
10
100
3
Sample Output:
67
13015
3
*/

#include<bits/stdc++.h>
using namespace std;

#define MAX 100005
typedef long long ll;
int phi[MAX];
void getPhi(int n){
    
    for(int i=0;i<=n;i++){
        phi[i] = i;
    }
    for(int i=2;i<=n;i++){
		if(phi[i]==i){
            for(int j=i;j<=n;j+=i){
                phi[j] = phi[j] - phi[j]/i;
            }
        }
    }
}

int main(){
    
    getPhi(MAX);
    ll result[MAX]={0};
    for(int i=1;i<MAX;i++){
		for(int j=2;i*j<MAX;j++){
            result[i*j] = result[i*j] + i*phi[j];
        }
    }
    for(int i=0;i<MAX;i++){
			result[i] = result[i-1] + result[i];
    }
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        ll answer = 0;
        answer = result[n];
        cout<<answer<<endl;
    }
    return 0;
}
