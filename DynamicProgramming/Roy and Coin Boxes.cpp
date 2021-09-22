/*
Roy has N coin boxes numbered from 1 to N.
Every day he selects two indices [L,R] and adds 1 coin to each coin box starting from L to R (both inclusive).
He does this for M number of days.
After M days, Roy has a query: How many coin boxes have at least X coins.
He has Q such queries.
Input Format:
First line will contain T (number of test case), format of each test case follows
First line contains two space separated integers N and M (N - number of coin boxes, M - number of days). Each of the next M lines consists of two space separated integers L and R. Followed by integer Q - number of queries.
Each of next Q lines contain a single integer X.
Output Format:
For each query of each test case output the result in a new line.
Constraints:
1 <= T <= 10
1 ≤ N ≤ 10000
1 ≤ M ≤ min(10000, N)
1 ≤ L ≤ R ≤ N
1 ≤ Q ≤ 10000
1 ≤ X ≤ N
Sample Input
1
7
4
1 3
2 5
1 2
5 6
4
1
7
4
2
Sample Output
6
0
0
4
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);

  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
  
    int s[n+1]={0}; // additions starts at i
    int e[n+1]={0}; // additions end at i
    int m;
    cin>>m;
    while(m--){
      int l,r;
      cin>>l>>r;
      s[l]++;  
      e[r]++;
    }
    
    int box[n+1]={0};
    for(int i=1;i<=n;i++){
      box[i] = s[i] + box[i-1] - e[i-1];  // addition starts at i + total additions at i - 1 that did not ended at i - 1;
    }
    // coin array to respond the query in constant time , hint at contraint : x <= n that means use of mapping is possible
    int coin[n+1]={0};
    for(int i=1;i<=n;i++){
      coin[box[i]]++;
    }
    for(int i=n-1;i>=1;i--){
      coin[i] = coin[i] + coin[i+1];
    }
    
    int q;
    cin>>q;
    while(q--){
      int x;
      cin>>x;
      cout<<coin[x]<<endl;
    }
  }
  return 0;
}