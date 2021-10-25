/*
Given a number, find the total number of divisors of the factorial of the number.
Since the answer can be very large, print answer modulo 10^9+7.
Input Format:
The first line contains T, number of test cases.
T lines follow each containing the number N.
Output Format:
Print T lines of output each containing the answer.
Constraints
1 <= T <= 500
0 <= N <= 50000
Sample Input:
3
2
3
4
Sample Output:
2
4
8
*/

#include<bits/stdc++.h>
using namespace std;

#define MAX 500001
#define pb push_back
typedef long long ll;


const unsigned int M = 1000000007;
bool isPrime[MAX];
vector<int> pr;
void seive(){
  memset(isPrime,true,sizeof(isPrime));
  isPrime[0] = false;
  isPrime[1] = false;  
  for(int i=2;i*i<MAX;i++){
    if(isPrime[i]){
      for(int j=i*i;j<MAX;j+=i){
        isPrime[j] = false;
      }
    }
  }
  for(int i=2;i<=MAX;i++){
      if(isPrime[i]){
		pr.push_back(i);
      }
  }
}
ll divisors(int n){

   ll result = 1;
    int sz = pr.size();
   //cout<<n<<endl;
   for(int i=0;pr[i]<=n; i++){
     int k = pr[i];
     //cout<<k<<endl;
     ll cnt = 0;
     while((n/k)!=0){
       cnt = (cnt + (n/k))%M;
       k = k*pr[i];
     }
     result = (result*((cnt%M + 1)%M))%M;
   }

   return result;
}

int main(){
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);

  int t;
  cin>>t;
  seive();
  while(t--){
    int n;
    cin>>n;
    cout<<divisors(n)<<endl;
  }
}