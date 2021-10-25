/*
Lex Luthor’s Legion of Doom is a tough organization to get into, even for greatest supervillains. Recently, a spot has opened up because The Mad Hatter has retired. Harley Quinn doesn't want to waste this opportunity, and jumps at the chance of the interview. But she has a PhD in psychology, not in Computer Science. She has kidnapped you and will let you go only if you are able to solve the evil questions of Lex Luthor.
You are given an array of N elements, which are initially all 0. After that you will be given C commands. They are -
0 p q v - you have to add v to all numbers in the range of p to q (inclusive), where p and q are two indexes of the array.
1 p q - output a line containing a single integer which is the sum of all the array elements between p and q (inclusive)
Input Format:
In the first line you'll be given T, number of test cases.

Each test case will start with N and C. After that you'll be given C commands in the format as mentioned above
Constraints:
 1 <= T <= 10
 1 <= N, C <= 10000
 1 <= val <= 10^8
 1 <= p <= q <= N
Output Format:
Print the answers of the queries in new line for each test case.
Sample Input 1:
1
8 6
0 2 4 26
0 4 8 80
0 4 5 20
1 8 8 
0 5 7 14
1 4 8
Sample Output 1:
80  
508
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void buildTree(int* a,ll* tree,int start,int end,int treeNode){

  if(start==end){
    tree[treeNode] = a[start];
    return;
  }
  int mid = start + (end - start)/2;

  buildTree(a,tree,start,mid,2*treeNode);
  buildTree(a,tree,mid+1,end,treeNode*2 + 1);
  tree[treeNode] = tree[treeNode*2] + tree[treeNode*2 + 1];
}

void updateSegTree(ll* tree,ll* lazy,int low,int high,int startR,int endR,int currPos,int inc){
  if(high<low){
    return;
  }


  if(lazy[currPos]!=0){
    tree[currPos] = tree[currPos] + (high-low+1)*lazy[currPos];
    if(low!=high){
      lazy[currPos*2] += lazy[currPos];
      lazy[currPos*2 + 1] += lazy[currPos];
    }
    lazy[currPos] = 0;
  }
  
  if(startR > high || endR < low){
    return;
  }

  if(startR<=low && high<=endR){
    ll mul = (high-low+1);
    tree[currPos] += mul*inc;
    if(low!=high){
      lazy[2*currPos] += inc;
      lazy[2*currPos + 1] += inc;
    }
    return;
  }

  ll mid = low + (high - low)/2;
  updateSegTree(tree,lazy,low,mid,startR,endR,2*currPos,inc);
  updateSegTree(tree,lazy,mid+1,high,startR,endR,2*currPos+1,inc);
  tree[currPos] = tree[currPos*2] + tree[2*currPos + 1];
}

ll msq(ll* tree,ll* lazy,int start,int end,int currPos,int left,int right){
  if(start>end){
    return -1;
  }

  if(lazy[currPos]!=0){
    tree[currPos] = tree[currPos] + (end-start+1)*lazy[currPos];
    if(start!=end){
      lazy[currPos*2] += lazy[currPos];
      lazy[currPos*2 + 1] += lazy[currPos];
    }
    lazy[currPos] = 0;
  }

  if(left > end || right < start){
    return -1;
  }

  if(start >= left && end <= right){
    return tree[currPos];
  }

  ll mid = start + (end - start)/2;
  ll p1 = msq(tree,lazy,start,mid,2*currPos,left,right);
  ll p2 = msq(tree,lazy,mid+1,end,2*currPos+1,left,right);
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
    int n;
    cin>>n;
    int a[n];
    memset(a,0,sizeof(a));
    int c;
    cin>>c;
    ll* tree = new ll[4*n]();
    buildTree(a,tree,0,n-1,1);
    
    ll* lazy = new ll[4*n]();
    
    for(int i=0;i<c;i++){
      int op;
      cin>>op;
      if(op==0){
        int p,q,v;
        cin>>p>>q>>v;
        p = p - 1;
        q = q - 1;
        updateSegTree(tree,lazy,0,n-1,p,q,1,v);
      }
      else{
        /*
        for(int i=0;i<4*n;i++){
          cout<<tree[i]<<" ";
        }
        cout<<endl;
        */
        int p,q;
        cin>>p>>q;
        p = p - 1;
        q = q - 1;
        cout<<msq(tree,lazy,0,n-1,1,p,q)<<endl;
      }
    }
  }
  return 0;
}