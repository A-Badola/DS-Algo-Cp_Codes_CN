/*
Tanmay and Rohit are best buddies. One day Tanmay gives Rohit a problem to test his intelligence and skills. He gives him an array of N natural numbers and asks him to solve the following queries:-
Query 0:
0 x y
This operation modifies the element present at index i to x.
Query 1:
1 x y 
This operation counts the number of even numbers in range l to r inclusive.
Query 2:
2 x y 
This operation counts the number of odd numbers in range l to r inclusive.
Input Format:
First line of the input contains the number N. 
Next line contains N natural numbers. 
Next line contains an integer Q followed by Q queries.
0 x y - modify the number at index x to y. 
1 x y - count the number of even numbers in range l to r inclusive.
2 x y - count the number of odd numbers in range l to r inclusive.
Constraints:
1<=N,Q<=10^5
1<=l<=r<=N 
0<=Ai<=10^9
1<=x<=N
0<=y<=10^9
Output Format:
 For each query, print the answer in a new line.
Note: Indexing starts from 1
Sample Input 1:
6
1 2 3 4 5 6
4
1 2 5
2 1 4
0 5 4
1 1 6
Sample Output 1:
2
2
4
*/

#include<bits/stdc++.h>
using namespace std;

struct node{
  int even;
  int odd;
};

void buildTree(int* a,node* tree,int start,int end,int treeNode){
    if(start==end){
        if(a[start] & 1){
          tree[treeNode].even = 0;
          tree[treeNode].odd = 1;
        }
        else{
          tree[treeNode].even = 1;
          tree[treeNode].odd = 0;
        }
        return;
    }
    
    int mid = start + (end - start)/2;
    buildTree(a,tree,start,mid,treeNode*2);
    buildTree(a,tree,mid+1,end,treeNode*2 + 1);
    tree[treeNode].even = tree[treeNode*2].even + tree[treeNode*2 + 1].even ;
    tree[treeNode].odd = tree[treeNode*2].odd + tree[treeNode*2 + 1].odd;
}

void updateTree(int* a,node* tree,int start,int end,int treeNode,int idx,int value){
    if(start==end){
        a[idx] = value;
        tree[treeNode].even = value & 1 ? 0 : 1; 
        tree[treeNode].odd = value & 1 ? 1 : 0;
        return;
    }
    
    int mid = start + (end - start)/2;
    if(idx > mid){
        updateTree(a,tree,mid+1,end,treeNode*2 + 1,idx,value);
    }
    else{
        updateTree(a,tree,start,mid,treeNode*2,idx,value);
    }
    tree[treeNode].even = tree[treeNode*2].even + tree[treeNode*2 + 1].even ;
    tree[treeNode].odd = tree[treeNode*2].odd + tree[treeNode*2 + 1].odd;
}

int mnqe(node* tree,int start,int end,int treeNode,int left,int right){
    if(start>right || left>end){
        return -1;
    }
    if(start>=left && end<=right){
        return tree[treeNode].even;
    }
    int mid = start + (end - start)/2;
    int p1 = mnqe(tree,start,mid,treeNode*2,left,right);
    int p2 = mnqe(tree,mid+1,end,treeNode*2 + 1,left,right);
    if(p1==-1)return p2;
    if(p2==-1)return p1;
    return p1 + p2;
}


int mnqo(node* tree,int start,int end,int treeNode,int left,int right){
    if(start>right || left>end){
        return -1;
    }
    if(start>=left && end<=right){
        return tree[treeNode].odd;
    }
    int mid = start + (end - start)/2;
    int p1 = mnqo(tree,start,mid,treeNode*2,left,right);
    int p2 = mnqo(tree,mid+1,end,treeNode*2 + 1,left,right);
    if(p1==-1)return p2;
    if(p2==-1)return p1;
    return p1 + p2;
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int q;
    cin>>q;
    node* tree = new node[4*n];
    for(int i=0;i<4*n;i++){
        tree[i].even = 0;
        tree[i].odd = 0;
    }

    buildTree(a,tree,0,n-1,1);

    int l,r,op;
    for(int i=0;i<q;i++){
        cin>>op>>l>>r;
        if(op==0){
                l = l-1;
                updateTree(a,tree,0,n-1,1,l,r);
        }
        else if(op==1){
                l = l-1;
                r = r-1;
                int ans = mnqe(tree,0,n-1,1,l,r);
                cout<<ans<<endl;
        }
        else{
                l = l-1;
                r = r-1;
                int ans = mnqo(tree,0,n-1,1,l,r);
                cout<<ans<<endl;
        }
    }
    return 0;
}