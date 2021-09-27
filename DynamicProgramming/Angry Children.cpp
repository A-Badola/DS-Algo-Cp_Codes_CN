/*
Bill Gates is on one of his philanthropic journeys to a village in Utopia. He has N packets of candies and would like to distribute one packet to each of the K children in the village (each packet may contain different number of candies). To avoid a fight between the children, he would like to pick K out of N packets such that the unfairness is minimized.
Suppose the K packets have (x1, x2, x3,....xk) candies in them, where xi denotes the number of candies in the ith packet, then we define unfairness as
unfairness=0;
for(i=0;i<n;i++)
    for(j=i;j<n;j++)
        unfairness+=abs(xi-xj)
abs(x) denotes absolute value of x.
Input Format:
First line will contain T(number of test cases), and each test case consists of two lines.
The first line contains two space-separated integers N and K.
The second line will contain N space-separated integers, where Ith integer denotes the candy in the Ith packet.
Output Format:
For each test case print a single integer which will be minimum unfairness in newline.
Constraints
1 <= T <= 10
2<=N<=10^5
2<=K<=N
0<= number of candies in each packet <=10^6
Sample Input
1
7 3
10 100 300 200 1000 20 30
Sample Output
40
Explanation
Bill Gates will choose packets having 10, 20 and 30 candies.So unfairness will be |10-20| + |20-30| + |10-30| = 40. We can verify that it will be minimum in this way.
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll minUnfair(ll* can,int n,int k){
  ll f_k = 0;
  ll sum_i = can[0];
  for(int i=1;i<k;i++){
    f_k = abs(f_k + i*can[i] - sum_i);
    sum_i = sum_i + can[i];
    //cout<<f_k<<" "<<sum_i<<endl;
  }
 // cout<<f_k<<" "<<sum_i<<endl;
  ll min_i = f_k;
  ll cur_k = f_k;
  for(int i=k;i<n;i++){
    cur_k = abs(cur_k + (k-1)*can[i-k] - 2*(sum_i - can[i-k]) +(k-1)*can[i]);
    sum_i = sum_i - can[i-k] + can[i];
    if(cur_k < min_i){
      min_i = cur_k;
    }
    //cout<<cur_k<<" "<<sum_i<<endl;
  }
  return min_i;
}
int main(){
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);

  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    int k;
    cin>>k;
    ll* can = new ll[n];
    for(int i=0;i<n;i++){
      cin>>can[i];
    }
    sort(can,can+n);
    cout<<minUnfair(can,n,k)<<endl;
    delete[] can;
  }
  return 0;
}