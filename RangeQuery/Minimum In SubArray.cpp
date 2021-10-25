/*
You are given a sequence A[1], A[2], ..., A[N] of N numbers ( 0 ≤ A[i] ≤ 10^8 , 2 ≤ N ≤ 10^5 ). There are Q queries, and each query is defined in either of the following two ways:
Query on range:
You are given two numbers i and j; the answer to each query is the minimum number between the range (i, j) (including both i and j). Note that in this query, i and j lies in the range: [1, N].
Update query:
You are given two numbers i and B; update A[i] to B. Note that in this query, i lies in the range: [1, N].
Input Format:
The first line of input contains two integers: N and Q, representing the length of the sequence and the number of queries. 
The second line of input contains N space-separated integers, A[i].  
Next, Q lines contain the queries. Each line contains one character, followed by two space-separated integers. For the query on range, the character will be q and for the update query, the character will be u. 
Constraints:
1 ≤ i ≤ N
0 ≤ B ≤ 10^8
1 ≤ i <= j ≤ N
Output Format:
For each query on range, print the minimum number between the range, in a new line.
Sample Input 1:
4 3
5 2 4 3
q 1 3
u 1 1
q 3 4
Sample Output 1:
2
3
*/

#include<bits/stdc++.h>
using namespace std;

void buildTree(int* a,int* tree,int start,int end,int treeNode){
    if(start==end){
        tree[treeNode] = a[start];
        return;
    }
    
    int mid = start + (end - start)/2;
    buildTree(a,tree,start,mid,treeNode*2);
    buildTree(a,tree,mid+1,end,treeNode*2 + 1);
    tree[treeNode] = min(tree[2*treeNode],tree[2*treeNode + 1]);
}

void updateTree(int* a,int* tree,int start,int end,int treeNode,int idx,int value){
    if(start==end){
        a[idx] = value;
        tree[treeNode] = value;
        return;
    }
    
    int mid = start + (end - start)/2;
    if(idx > mid){
        updateTree(a,tree,mid+1,end,treeNode*2 + 1,idx,value);
    }
    else{
        updateTree(a,tree,start,mid,treeNode*2,idx,value);
    }
    tree[treeNode] = min(tree[treeNode*2],tree[2*treeNode + 1]);
}

int mnq(int* tree,int start,int end,int treeNode,int left,int right){
    if(start>right || left>end){
        return -1;
    }
    if(start>=left && end<=right){
        return tree[treeNode];
    }
    int mid = start + (end - start)/2;
    int p1 = mnq(tree,start,mid,treeNode*2,left,right);
    int p2 = mnq(tree,mid+1,end,treeNode*2 + 1,left,right);
    if(p1==-1)return p2;
    if(p2==-1)return p1;
    return min(p1,p2);
}

int main(){
    
    int n,q;
    cin>>n>>q;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    int* tree = new int[4*n];
    for(int i=0;i<4*n;i++){
        tree[i] = 0;
    }
    buildTree(a,tree,0,n-1,1);
    int l,r;
    char op;
    for(int i=0;i<q;i++){
        cin>>op>>l>>r;
       	if(op=='u'){
            l = l-1;
            updateTree(a,tree,0,n-1,1,l,r);
        }
    	else{
            l = l-1;
            r = r-1;
            int ans = mnq(tree,0,n-1,1,l,r);
            cout<<ans<<endl;
        }
    }
    return 0;
}
