/*
RQ2
Given a sequence of N integers S1, ..., SN, compute the number of increasing subsequences of S with length K and that is, the number of K-tuples i1, ..., iK such that 1 ≤ i1 < ... < iK ≤ N and Si1 < ... < SiK.
Input Format:
The first line contains the two integers N and K. 
Next line contains N space-separated integers denoting the elements of the array.
Constraints:
 1 <= N <= 10^4
 1 <= K <= 50
 1 <= arr[i] <= 10^5
Output Format:
Print a single integer representing the number of increasing subsequences of S of length K, modulo 5,000,000.
Sample Input 1:
4 3
1 2 2 10
Sample Output 1:
2
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const unsigned int M = 5000000;
ll bit[51][100005];

void update(int index, int num, int value){
  for(;index<=100005;index+=index & (-index)){
    bit[num][index] = (bit[num][index] + value)%M;
  }
}

ll query(int index, int num){
  ll sum = 0;
  for(;index>0;index-=index&(-index)){
    sum += (bit[num][index])%M;
    sum = sum%M;
  }
  return sum;
}
int main(){
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);

  int n,k;
  cin>>n>>k;
  int a[n+1];
  for(int i=1;i<=n;i++){
    cin>>a[i];
  }
  ll add = 0;
  ll ans = 0;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=k;j++){
      if(j==1){
        add = 1;
      }
      else{
        add = query(a[i],j-1);
      }
      update(a[i]+1,j,add);
      if(j==k){
        ans = (ans + add)%M;
      }
    }
  }
  cout<<ans;
  return 0;
}