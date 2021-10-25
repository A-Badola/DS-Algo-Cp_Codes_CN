/*
King Leonidas of Sparta is preparing his men and country for a war against the Persian King Xerxes. He has N soldiers with him and he has arranged them in a line at The Hot Gates. Let us number them from 1 to N. Leonidas will fight Xerxes' army for Q days, and each day he can send only one of his men to fight.
For each warrior, we know 2 traits: Strength and Cowardice. These are given to us in a form of integer. Each day, Leonidas can choose his warrior from a range Li to Ri, and he will choose the warrior with maximum Strength value. If there is more than one warrior having the same maximum Strength value, he will choose the warrior with minimum Cowardice value. If there is still more than 1 warrior with the same maximum Strength value and same minimum Cowardice value, he chooses the one with lower index in line.
King Leonidas is ready to lay his life for Sparta. You, his right hand man, have to help him save Sparta by helping him choose a warrior for each day.
Input Format:
First line contains a single integer N, denoting the number of warriors Leonidas has. 
Second line contains N space separated integers, representing Strength of ith warrior. 
Third line contains N space separated integers, representing Cowardice of ith warrior
Next line contains a single integer Q, denoting the number of days Queen Vasya chooses a warrior. 
Each of the next Q lines contains 2 integers Li and Ri.
Constraints:
1 ≤ N,Q ≤ 10^5
1 ≤ Ai,Bi ≤ 10^9
1 ≤ Li ≤ Ri
Output Format:
For each Li and Ri, print the index of the warrior that King Leonidas should choose.
Sample Input 1:
5
1 8 4 6 8
4 8 6 3 7
4
1 4
2 4
3 4
1 5
Sample Output 1:
2
2
4
5
*/

#include<bits/stdc++.h>
using namespace std;

struct node{
  int strength;
  int cowardice;
};

void buildTree(node* a,int* tree,int start,int end,int treeNode){
    if(start==end){
        tree[treeNode] = start;
        return;
    }
    
    int mid = start + (end - start)/2;
    buildTree(a,tree,start,mid,treeNode*2);
    buildTree(a,tree,mid+1,end,treeNode*2 + 1);
    int ln = 2*treeNode;
    int rn = 2*treeNode + 1;
    if(a[tree[ln]].strength > a[tree[rn]].strength){
      tree[treeNode] = tree[ln];
    }
    else if(a[tree[ln]].strength == a[tree[rn]].strength){
      if(a[tree[ln]].cowardice < a[tree[rn]].cowardice){
        tree[treeNode] = tree[ln];
      }
      else if(a[tree[ln]].cowardice == a[tree[rn]].cowardice){
        if(tree[ln] < tree[rn]){
          tree[treeNode] = tree[ln];
        }
        else{
          tree[treeNode] = tree[rn];
        }
      }
      else{
        tree[treeNode] = tree[rn];
      }
    }
    else{
      tree[treeNode] = tree[rn];
    }
}


int bs(node* a,int* tree,int start,int end,int treeNode,int left,int right){
    if(start>right || left>end){
        return -1;
    }
    if(start>=left && end<=right){
        return tree[treeNode];
    }
    int mid = start + (end - start)/2;
    int p1 = bs(a,tree,start,mid,treeNode*2,left,right);
    int p2 = bs(a,tree,mid+1,end,treeNode*2 + 1,left,right);
    if(p1==-1)return p2;
    if(p2==-1)return p1;
    if(a[p1].strength > a[p2].strength){
      return p1;
    }
    else if(a[p1].strength == a[p2].strength){
      if(a[p1].cowardice < a[p2].cowardice){
        return p1;
      }
      else if(a[p1].cowardice == a[p2].cowardice){
        if(p1 < p2){
          return p1;
        }
        else{
          return p2;
        }
      }
      else{
        return p2;
      }
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
    node a[n];
    for(int i=0;i<n;i++){
      cin>>a[i].strength;
    }
    for(int i=0;i<n;i++){
      cin>>a[i].cowardice;
    }
    int q;
    cin>>q;
    int* tree = new int[4*n];
    for(int i=0;i<4*n;i++){
        tree[i] = 0;
    }

    buildTree(a,tree,0,n-1,1);

    int l,r;
    for(int i=0;i<q;i++){
        cin>>l>>r;
        l = l-1;
        r = r-1;
        int ans = bs(a,tree,0,n-1,1,l,r);
        cout<<(ans+1)<<endl;
    }
    return 0;
}