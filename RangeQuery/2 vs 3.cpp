/*
The fight for the best number in the globe is going to finally come to an end.The top two contenders for the best number are number 2 and number 3.It's the final the entire world was waiting for. Expectorates from all across the globe came to witness the breath taking finals.
The finals began in an astonishing way.A common problem was set for both of them which included both these number.The problem goes like this.
Given a binary string (that is a string consisting of only 0 and 1). They were supposed to perform two types of query on the string.
Type 0: Given two indices l and r.Print the value of the binary string from l to r modulo 3.

Type 1: Given an index l flip the value of that index if and only if the value at that index is 0.
The problem proved to be a really tough one for both of them.Hours passed by but neither of them could solve the problem.So both of them wants you to solve this problem and then you get the right to choose the best number in the globe.
Input format:
The first line contains N denoting the length of the binary string .
The second line contains the N length binary string.Third line contains the integer Q indicating the number of queries to perform.
This is followed up by Q lines where each line contains a query.
Output format:
For each query of Type 0 print the value modulo 3.
Constraints:
1<= N <=10^5
1<= Q <= 10^5
0 <= l <= r < N
Sample Input
5
10010
6
0 2 4
0 2 3
1 1
0 0 4
1 1
0 0 3
Sample Output
2
1
2
1
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
void buildTree(string& a,int* tree,int start,int end,int treeNode){
    if(start==end){
        if(a[start]=='0'){
          tree[treeNode] = 0;
        }
        else{
          tree[treeNode] = 1;
        }
        //cout<<treeNode<<" "<<tree[treeNode]<<endl;
        return;
    }
    
    ll mid = start + (end - start)/2;
    buildTree(a,tree,start,mid,treeNode*2);
    buildTree(a,tree,mid+1,end,treeNode*2 + 1);
	ll mul = ((end - mid) & 1 ? 2 : 1);
    tree[treeNode] = ((tree[2*treeNode]*mul)%3 + tree[2*treeNode + 1])%3;
}

void updateTree(string& a,int* tree,int start,int end,int treeNode,int idx){
    if(start==end && start==idx){
        a[start] = a[start]=='0'? '1' : a[start];
        if(a[start]=='0'){
          tree[treeNode] = 0;
        }
        else{
          tree[treeNode] = 1;
        }
        return;
    }
    
    ll mid = start + (end - start)/2;
    if(idx > mid){
        updateTree(a,tree,mid+1,end,treeNode*2 + 1,idx);
    }
    else{
        updateTree(a,tree,start,mid,treeNode*2,idx);
    }
    ll mul = ((end - mid) & 1 ? 2 : 1);
    tree[treeNode] = ((tree[2*treeNode]*mul)%3 + tree[2*treeNode + 1])%3;
}

ll rq(int* tree,int start,int end,int treeNode,int left,int right){
    if(start>right || left>end){
        return -1;
    }
    if(start>=left && end<=right){
        return tree[treeNode];
    }
    ll mid = start + (end - start)/2;
    ll p1 = rq(tree,start,mid,treeNode*2,left,right);
    ll p2 = rq(tree,mid+1,end,treeNode*2 + 1,left,right);
    ll mul = ((min(right,end) - mid) & 1 ? 2 : 1);
    if(p1==-1)return p2;
    if(p2==-1)return p1;
    
    return ((p1*mul)%3 + p2%3)%3;
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n;
    cin>>n;
    string a;
    cin>>a;
    ll q;
    cin>>q;
    int* tree = new int[4*n];
    for(ll i=0;i<4*n;i++){
        tree[i] = 0;
    }

    buildTree(a,tree,0,n-1,1);
    ll op;
    for(int i=0;i<q;i++){
        cin>>op;
        if(op==0){
                ll l,r;
                cin>>l>>r;
                ll ans = rq(tree,0,n-1,1,l,r);
                cout<<ans<<endl;
        }
        else{ 
                ll ind;
                cin>>ind;
                updateTree(a,tree,0,n-1,1,ind);
                //cout<<a<<endl;
        }
    }
    return 0;
}