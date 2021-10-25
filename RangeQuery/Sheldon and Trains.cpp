/*
Sheldon always tells people, “When you have only one day to visit Los Angeles, make it a Train Day”. He loves spending time while travelling in trains and considers it a fun activity. Sheldon’s mom has come to visit him and he decides to take her out on a train tour of the city of Pasadena, along with his friend Howard. There are n train stations in the city. Howard knows how irritating Sheldon can be during a train ride. So, to keep him busy, Howard gives Sheldon a problem so interesting that he just cannot do anything else other than devote his entire mind to solving it. The problem goes like this. At the i-th station it's possible to buy only tickets to stations from i + 1 to ai (inclusive). No tickets are sold at the last station.
Let ρi, j be the minimum number of tickets one needs to buy in order to get from stations i to station j. Sheldon’s task is to compute the sum of all values ρi, j among all pairs 1 ≤ i < j ≤ n. As brilliant as he may be, he asked for your help.
Input Format:
First line of input will contain N number of trains 
Second line will contain N-1 space-separated integers denoting the values of ai
Output Format:
Print the answer as mentioned above
Constraints:
2 < = N <= 10^5
i + 1 <=arr[i] <= N
Sample Input 1:
7
2 7 5 7 6 7 
Sample Output 1:
29
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void buildTree(int* a,pair<int,int>* tree,int start,int end,int treeNode){
    if(start==end){
        tree[treeNode].first = a[start];
        tree[treeNode].second = start;
        return;
    }
    
    int mid = start + (end - start)/2;
    buildTree(a,tree,start,mid,treeNode*2);
    buildTree(a,tree,mid+1,end,treeNode*2 + 1);
    int left = 2*treeNode;
    int right = 2*treeNode + 1;
    tree[treeNode] = max(tree[left],tree[right]); 
}


int miq(int a[],pair<int,int>* tree,int start,int end,int treeNode,int left,int right){
    if(start>right || left>end){
        return -1;
    }
    if(start>=left && end<=right){
        return tree[treeNode].second;
    }
    int mid = start + (end - start)/2;
    int p1 =miq(a,tree,start,mid,treeNode*2,left,right);
    int p2 = miq(a,tree,mid+1,end,treeNode*2 + 1,left,right);
    if(p1==-1)return p2;
    if(p2==-1)return p1;
    if(a[p1] >= a[p2]){
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
    for(int i=0;i<n-1;i++){
        cin>>a[i];
        a[i] = a[i] - 1; //0 indexing
    }
    a[n-1] = n-1;
    pair<int,int>* tree = new pair<int,int>[4*n]();
    buildTree(a,tree,0,n-1,1);

    ll dp[n];
    dp[n-1] = 0;
    ll ans = 0;
    for(int i=n-2;i>=0;i--){
        int k = miq(a,tree,0,n-1,1,i+1,a[i]);
        dp[i] = n-1-i - (a[i]-k) + dp[k];
        ans = ans + dp[i];
    }
    cout<<ans;
}