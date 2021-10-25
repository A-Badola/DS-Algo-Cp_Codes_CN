/*
You are given a sequence A[1], A[2], ..., A[N], ( 0 ≤ A[i] ≤ 10^8 , 2 ≤ N ≤ 10^5 ). There are two types of operations and they are defined as follows:
Update:
This will be indicated in the input of a 'U' followed by space and then two integers i and x.
U i x
This operation sets the value of A[i] to x.
Query:
This will be indicated in the input of a 'Q' followed by a single space and then two integers i and j.
Q x y
You must find two integers i and j such that x ≤ i, j ≤ y and i != j, such that the sum A[i]+A[j] is maximized. Print the sum A[i]+A[j].
Input Format:
The first line of input contains an integer N, representing the length of the sequence. 
The second line of input contains of N space separated integers, A[i]. 
The third line of input contains an integer Q, Q ≤ 10^5, representing the number of operations. 
Next Q lines contain the operations.
Constraints:
1 ≤ i ≤ N
0 ≤ x ≤ 10^8
1 ≤ x < y ≤ N
Output Format:
For each query, print the maximum sum mentioned above, in a new line.
Sample Input 1:
5
1 2 3 4 5
6
Q 2 4
Q 2 5
U 1 6
Q 1 5
U 1 7
Q 1 5
Sample Output 1:
7
9
11
12
*/

#include<bits/stdc++.h>
using namespace std;

void buildTree(int* a,int* tree,int start,int end,int treeNode){
    if(start==end){
        tree[treeNode] = start;
        return;
    }
    
    int mid = start + (end - start)/2;
    buildTree(a,tree,start,mid,treeNode*2);
    buildTree(a,tree,mid+1,end,treeNode*2 + 1);
    if(a[tree[2*treeNode]]>a[tree[2*treeNode + 1]]){
      tree[treeNode] = tree[2*treeNode];
    }
    else{
      tree[treeNode] = tree[2*treeNode + 1];
    } 
}

void updateTree(int* a,int* tree,int start,int end,int treeNode,int idx,int value){
    if(start==end){
        a[idx] = value;
        tree[treeNode] = idx;
        return;
    }
    
    int mid = start + (end - start)/2;
    if(idx > mid){
        updateTree(a,tree,mid+1,end,treeNode*2 + 1,idx,value);
    }
    else{
        updateTree(a,tree,start,mid,treeNode*2,idx,value);
    }
    if(a[tree[2*treeNode]]>a[tree[2*treeNode + 1]]){
      tree[treeNode] = tree[2*treeNode];
    }
    else{
      tree[treeNode] = tree[2*treeNode + 1];
    }
}

int mpq(int a[],int* tree,int start,int end,int treeNode,int left,int right){
    if(start>right || left>end){
        return -1;
    }
    if(start>=left && end<=right){
        return tree[treeNode];
    }
    int mid = start + (end - start)/2;
    int p1 = mpq(a,tree,start,mid,treeNode*2,left,right);
    int p2 = mpq(a,tree,mid+1,end,treeNode*2 + 1,left,right);
    if(p1==-1)return p2;
    if(p2==-1)return p1;
    if(a[p1]>=a[p2]){
      return p1;
    }
    else{
      return p2;
    }
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
    int* tree = new int[4*n];
    for(int i=0;i<4*n;i++){
        tree[i] = 0;
    }
    buildTree(a,tree,0,n-1,1);
    int l,r;
    char op;
    /*
    for(int i=0;i<4*n;i++){
      cout<<tree[i]<<" ";
    }
    cout<<endl;
    */
    for(int i=0;i<q;i++){
        cin>>op>>l>>r;
        if(op=='U'){
                l = l-1;
                updateTree(a,tree,0,n-1,1,l,r);
        }
        else{
                l = l-1;
                r = r-1;
                int mx1 = mpq(a,tree,0,n-1,1,l,r);
                int cmx2 = mpq(a,tree,0,n-1,1,mx1+1,r);
                int cmx3 = mpq(a,tree,0,n-1,1,l,mx1-1);
                int mx2;
                if(a[cmx2]>a[cmx3]){
                  mx2 = cmx2;
                }
                else{
                  mx2 = cmx3;
                }
                int ans = a[mx1] + a[mx2];
                cout<<ans<<endl;
        }
    }
    return 0;
}