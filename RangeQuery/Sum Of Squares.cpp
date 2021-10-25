/*
Segment trees are extremely useful. In particular "Lazy Propagation" (i.e. see here, for example) allows one to compute sums over a range in O(lg(n)), and update ranges in O(lg(n)) as well. In this problem you will compute something much harder:
The sum of squares over a range with range updates of 2 types:
1) increment in a range
2) set all numbers the same in a range.
There will be T test cases in the input file. First line of the input contains two positive integers, N and Q.
The next line contains N integers, each at most 1000. Each of the next Q lines starts with a number, which indicates the type of operation:
2 st nd -- return the sum of the squares of the numbers with indices in [st, nd] {i.e., from st to nd inclusive} (1 <= st <= nd <= N).

1 st nd x -- add "x" to all numbers with indices in [st, nd] (1 <= st <= nd <= N, and 1 <= x <= 1,000).

0 st nd x -- set all numbers with indices in [st, nd] to "x" (1 <= st <= nd <= N, and 1 <= x <= 1,000).
Input Format:
First line of input will contain T(number of test case), each test case follows as.
Line 1: contain two space-separated integers denoting the value of N and Q respectively
Line 2: contain N space-separated integers denoting th value of array elements
Next Q line contain the space separated value for queries as defined as above.
Constraints:
1 <= T <= 10
1 <= N <= 10000
1 <= arr[i] <= 1000
1 <= Q <= 10000
Output Format:
For each test case, print the answer in new line for query of type 2
Sample Input 1:
2
4 5
1 2 3 4
2 1 4
0 3 4 1
2 1 4
1 3 4 1
2 1 4
1 1
1
2 1 1
Sample Output 1:
30
7
13
1
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct node{
  ll sqSum;
  ll sum;
};

struct lnode{
  ll set;
  ll inc;
  int lat;
};

void buildTree(int* a,node* tree,ll start,ll end,ll treeNode){

  if(start==end){
    tree[treeNode].sqSum = a[start]*a[start];
    tree[treeNode].sum = a[start];
    return;
  }
  int mid = start + (end - start)/2;

  buildTree(a,tree,start,mid,2*treeNode);
  buildTree(a,tree,mid+1,end,treeNode*2 + 1);
  tree[treeNode].sqSum = tree[treeNode*2].sqSum + tree[treeNode*2 + 1].sqSum;
  tree[treeNode].sum = tree[treeNode*2].sum + tree[treeNode*2 + 1].sum;
}


void updateSegTree_set(node* tree,lnode* lazy,ll low,ll high,ll startR,ll endR,ll currPos,ll x){
  if(high<low){
    return;
  }

  if(lazy[currPos].lat==1){
    if(lazy[currPos].set!=0){
    ll temp = lazy[currPos].set;
    tree[currPos].sqSum = (high-low+1)*temp*temp;
    tree[currPos].sum = (high-low+1)*temp;
    if(low!=high){
      lazy[currPos*2].set = lazy[currPos].set;
      lazy[currPos*2 + 1].set = lazy[currPos].set;
      lazy[currPos*2].inc = 0;
      lazy[currPos*2+1].inc = 0;
      lazy[currPos*2].lat = 1;
      lazy[currPos*2 + 1].lat = 1;
    }
    lazy[currPos].set = 0;
    lazy[currPos].inc = 0;
    lazy[currPos].lat = 0;
  }
  }
  else if(lazy[currPos].lat==2){
    
   
      if(lazy[currPos].set!=0){
    ll temp = lazy[currPos].set;
    tree[currPos].sqSum = (high-low+1)*temp*temp;
    tree[currPos].sum = (high-low+1)*temp;
    if(low!=high){
      lazy[currPos*2].set = lazy[currPos].set;
      lazy[currPos*2 + 1].set = lazy[currPos].set;
		lazy[currPos*2].inc = 0;
      lazy[currPos*2+1].inc = 0;
        lazy[currPos*2].lat = 1;
      lazy[currPos*2 + 1].lat = 1;
    }
    lazy[currPos].set = 0;
        lazy[currPos].lat = 0;
  }
      if(lazy[currPos].inc!=0){
    ll temp = lazy[currPos].inc;
    tree[currPos].sqSum += (high-low+1)*temp*temp + 2*tree[currPos].sum*temp;
    tree[currPos].sum += (high-low+1)*temp;
    if(low!=high){
      lazy[currPos*2].inc += lazy[currPos].inc;
      lazy[currPos*2 + 1].inc += lazy[currPos].inc;
         lazy[currPos*2].lat = 2;
      lazy[currPos*2 + 1].lat = 2;
    }
    lazy[currPos].inc = 0;
       lazy[currPos].lat = 0;
  }
  }

  if(startR > high || endR < low){
    return;
  }

  if(startR<=low && high<=endR){
    ll mul = (high-low+1);
    tree[currPos].sqSum = mul*x*x;
    tree[currPos].sum = mul*x;
    if(low!=high){
      lazy[currPos*2].set = x;
      lazy[currPos*2 + 1].set = x;
        lazy[currPos*2].inc = 0;
      lazy[currPos*2+1].inc = 0;
      lazy[currPos*2].lat = 1;
      lazy[currPos*2 + 1].lat = 1;
    }
    return;
  }

  ll mid = low + (high - low)/2;
  updateSegTree_set(tree,lazy,low,mid,startR,endR,2*currPos,x);
  updateSegTree_set(tree,lazy,mid+1,high,startR,endR,2*currPos+1,x);
  tree[currPos].sqSum = tree[currPos*2].sqSum + tree[currPos*2 + 1].sqSum;
  tree[currPos].sum = tree[currPos*2].sum + tree[currPos*2 + 1].sum;
}


void updateSegTree_inc(node* tree,lnode* lazy,ll low,ll high,ll startR,ll endR,ll currPos,ll x){
  if(high<low){
    return;
  }
  if(lazy[currPos].lat==1){
    if(lazy[currPos].set!=0){
    ll temp = lazy[currPos].set;
    tree[currPos].sqSum = (high-low+1)*temp*temp;
    tree[currPos].sum = (high-low+1)*temp;
    if(low!=high){
      lazy[currPos*2].set = lazy[currPos].set;
      lazy[currPos*2 + 1].set = lazy[currPos].set;
      lazy[currPos*2].inc = 0;
      lazy[currPos*2+1].inc = 0;
      lazy[currPos*2].lat = 1;
      lazy[currPos*2 + 1].lat = 1;
    }
    lazy[currPos].set = 0;
    lazy[currPos].inc = 0;
    lazy[currPos].lat = 0;
  }
  }
  else if(lazy[currPos].lat==2){
    
   
      if(lazy[currPos].set!=0){
    ll temp = lazy[currPos].set;
    tree[currPos].sqSum = (high-low+1)*temp*temp;
    tree[currPos].sum = (high-low+1)*temp;
    if(low!=high){
      lazy[currPos*2].set = lazy[currPos].set;
      lazy[currPos*2 + 1].set = lazy[currPos].set;
        lazy[currPos*2].lat = 1;
      lazy[currPos*2 + 1].lat = 1;
    }
    lazy[currPos].set = 0;
        lazy[currPos].lat = 0;
  }
      if(lazy[currPos].inc!=0){
    ll temp = lazy[currPos].inc;
    tree[currPos].sqSum += (high-low+1)*temp*temp + 2*tree[currPos].sum*temp;
    tree[currPos].sum += (high-low+1)*temp;
    if(low!=high){
      lazy[currPos*2].inc += lazy[currPos].inc;
      lazy[currPos*2 + 1].inc += lazy[currPos].inc;
         lazy[currPos*2].lat = 2;
      lazy[currPos*2 + 1].lat = 2;
    }
    lazy[currPos].inc = 0;
       lazy[currPos].lat = 0;
  }
  }
  
  if(startR > high || endR < low){
    return;
  }

  if(startR<=low && high<=endR){
    ll mul = (high-low+1);
    tree[currPos].sqSum += mul*x*x + 2*tree[currPos].sum*x;
    tree[currPos].sum += mul*x;
    if(low!=high){
      lazy[currPos*2].inc += x;
      lazy[currPos*2 + 1].inc += x;
      lazy[currPos*2].lat = 2;
      lazy[currPos*2 + 1].lat = 2;
    }
    return;
  }

  ll mid = low + (high - low)/2;
  updateSegTree_inc(tree,lazy,low,mid,startR,endR,2*currPos,x);
  updateSegTree_inc(tree,lazy,mid+1,high,startR,endR,2*currPos+1,x);
  tree[currPos].sqSum = tree[currPos*2].sqSum + tree[currPos*2 + 1].sqSum;
  tree[currPos].sum = tree[currPos*2].sum + tree[currPos*2 + 1].sum;
}


ll ssq(node* tree,lnode* lazy,ll low,ll high,ll currPos,ll left,ll right){
  if(low>high){
    return -1;
  }
  if(lazy[currPos].lat==1){
    if(lazy[currPos].set!=0){
    ll temp = lazy[currPos].set;
    tree[currPos].sqSum = (high-low+1)*temp*temp;
    tree[currPos].sum = (high-low+1)*temp;
    if(low!=high){
      lazy[currPos*2].set = lazy[currPos].set;
      lazy[currPos*2 + 1].set = lazy[currPos].set;
        lazy[currPos*2].inc = 0;
      lazy[currPos*2+1].inc = 0;
      lazy[currPos*2].lat = 1;
      lazy[currPos*2 + 1].lat = 1;
    }
    lazy[currPos].set = 0;
    lazy[currPos].inc = 0;
    lazy[currPos].lat = 0;
  }
  }
  else if(lazy[currPos].lat==2){
    
      if(lazy[currPos].set!=0){
    ll temp = lazy[currPos].set;
    tree[currPos].sqSum = (high-low+1)*temp*temp;
    tree[currPos].sum = (high-low+1)*temp;
    if(low!=high){
      lazy[currPos*2].set = lazy[currPos].set;
      lazy[currPos*2 + 1].set = lazy[currPos].set;
        lazy[currPos*2].inc = 0;
      lazy[currPos*2+1].inc = 0;
        lazy[currPos*2].lat = 1;
      lazy[currPos*2 + 1].lat = 1;
    }
    lazy[currPos].set = 0;
        lazy[currPos].lat = 0;
  }
      
      if(lazy[currPos].inc!=0){
    ll temp = lazy[currPos].inc;
    tree[currPos].sqSum += (high-low+1)*temp*temp + 2*tree[currPos].sum*temp;
    tree[currPos].sum += (high-low+1)*temp;
    if(low!=high){
      lazy[currPos*2].inc += lazy[currPos].inc;
      lazy[currPos*2 + 1].inc += lazy[currPos].inc;
         lazy[currPos*2].lat = 2;
      lazy[currPos*2 + 1].lat = 2;
    }
    lazy[currPos].inc = 0;
       lazy[currPos].lat = 0;
  }
  }
  
   
  
  if(left > high || right < low){
    return -1;
  }

  if(low >= left && high <= right){
    return tree[currPos].sqSum;
  }

  ll mid = low + (high - low)/2;
  ll p1 = ssq(tree,lazy,low,mid,2*currPos,left,right);
  ll p2 = ssq(tree,lazy,mid+1,high,2*currPos+1,left,right);
  if(p1==-1) return p2;
  if(p2==-1) return p1;
  ll ans = p1 + p2;
  return ans;
}


int main(){
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);

  int t;
  cin>>t;
  while(t--){
  int n,q;
  cin>>n>>q;

  int a[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }

  //for(int i=0;i<n;i++){
   // cout<<a[i]<<" ";
  //}
  //cout<<endl;

  node* tree = new node[4*n]();
  lnode* lazy = new lnode[4*n]();

  buildTree(a,tree,0,n-1,1);
  //for(int i=0;i<4*n;i++){
   // cout<<tree[i].sqSum<<" ";
  //}
  //cout<<endl;

  for(int i=0;i<q;i++){
    int qtype;
    cin>>qtype;
    if(qtype==0){
      ll st,nd,x;
      cin>>st>>nd>>x;
      st = st-1;
      nd = nd-1;
      updateSegTree_set(tree,lazy,0,n-1,st,nd,1,x);
      //for(int i=0;i<4*n;i++){
       // cout<<tree[i].sqSum<<" ";
      //}
      //cout<<endl;
    }
    else if(qtype==1){
      ll st,nd,x;
      cin>>st>>nd>>x;
      st=st-1;
      nd=nd-1;
      updateSegTree_inc(tree,lazy,0,n-1,st,nd,1,x);
      //for(int i=0;i<4*n;i++){
       // cout<<tree[i].sqSum<<" ";
      //}
      //cout<<endl;
    }
    else{
      ll st,nd;
      cin>>st>>nd;
      st=st-1;
      nd=nd-1;
      ll k = ssq(tree,lazy,0,n-1,1,st,nd);
      cout<<k<<endl;
    }
  }
  }
  return 0;
}