/*
RQ2
Given a sequence of n numbers a1, a2, ..., an and a number of k- queries. A k-query is a triple (i, j, k) (1 ≤ i ≤ j ≤ n). For each k-query (i, j, k), you have to return the number of elements greater than k in the subsequence ai, ai+1, ..., aj.
Input Format
Line 1: Contains an integer N denoting the number of elements in the array
Line 2: N space-separated integers denoting the elements of the array.
Line 3: Number of queries Q
Next Q line contain two space-separated integers i, j, k descrbing the current query
Constraints:
1 <= N <= 10^5
1 <= Q <= 10^5
1 <= arr[i] <= 10^9
1 <= i <= j <= N
1 <= k <= 10^9
Output Format:
For each k-query (i, j, k), print the number of elements greater than k in the subsequence ai, ai+1, ..., aj in a single line.
Sample Input 1:
5
5 1 2 3 4
3
2 4 1
4 4 4
1 5 2 
Sample Output 1:
2
0
3 
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
struct node{
  int l;
  int r;
  ll k;
  int index;
};

bool compare(node a,node b){
  if(a.k==b.k){
    return a.l > b.l;
  }
  return a.k > b.k;
}

int qry(int r,int n,int* bit)
{
    int ans=0;
    while(r>0)
    {
        ans+=bit[r];
        r-=(r&-r);
    }
    return ans;
}
void update(int i,int n,int* bit)
{
    while(i<=n)
        bit[i]++,i+=(i&-i);

}

int main(){
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);

  int n;
  cin>>n;
  vector<pair<int,int>> a(n+1);
  for(int i=1;i<=n;i++){
    cin>>a[i].first;
    a[i].second = i;
  }
  sort(a.begin(),a.end());
  int q;
  cin>>q;
  node query[q];
  for(int i=0;i<q;i++){
    cin>>query[i].l>>query[i].r>>query[i].k;
    query[i].index = i;
  } 

  sort(query, query+q, compare);

  int* bit = new int[n+1]();
  int* ans = new int[q+1]();


  for(int i=0;i<q;i++){
    int k = query[i].k;
    int ind = query[i].index;
    int l = query[i].l;
    int r = query[i].r;

    int j = a.size()-1;
    while(j>=0){
      if(a[j].first>k){
        update(a[j].second,n,bit);
        a.pop_back();
      }
      else{
        break;
      }
      j--;
    }
 
    ans[ind] = qry(r,n,bit) - qry(l-1,n,bit);
  }

  for(int i=0; i<q; i++){
    cout<<ans[i]<<"\n";
  }
  return 0;
}