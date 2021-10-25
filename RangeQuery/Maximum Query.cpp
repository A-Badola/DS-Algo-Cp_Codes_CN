/*
You are given an array of integet of size N and Q queries in form of (l, r). You are supposed to find the maximum value of array between index l and r (both inclusive)
Input Format:
First line of input contain an integer N (number of elements in the array)
Second line contain N space-separated integers denoting the elements of the array
Third line contain an integer Q (number of queries to be processed)
Next Q line contain two space-separated integers denoting l and r.
Output Format:
For each test case print the output in newline.
Constraints:
1 <= N <= 10^4
1 <= Q <= 10^6
1 <= arr[i] <= 10^9
0 <= l <= r < N
Sample Input:
5
1 2 3 5 4
2 
0 1
3 4
Sample Output:
2
5
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
    /*
    for(int i=0;i<4*n;i++){
      cout<<tree[i]<<" ";
    }
    cout<<endl;
    */
    for(int i=0;i<q;i++){
        cin>>l>>r;
        int mx1 = mpq(a,tree,0,n-1,1,l,r);
        int ans = a[mx1];
        cout<<ans<<endl;
    }
    return 0;
}