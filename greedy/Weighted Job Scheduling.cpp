/*
You are given N jobs where every job is represented as:
1. Start Time
2. Finish Time
3. Profit Associated
Find the maximum profit subset of jobs such that no two jobs in the subset overlap.
Input Format:
The first line of input contains an integer denoting N.
Next N lines contains three space separated integers denoting the start time, finish time and the profit associated with the ith job. 
Constraints:
1 ≤ N ≤ 10^6
1 ≤ ai, di, p ≤ 10^6
Output Format:
Output one integer, the maximum profit that can be achieved.
Sample Input 1
4
3 10 20
1 2 50
6 19 100
2 100 200
Sample Output 1
250
*/

#include<bits/stdc++.h>
using namespace std;
int bsearch(vector<pair<pair<int,int>,int>>& v,int low,int high,int target){
    int mid;
    int ans=high;
    while(low<=high){
        mid = low + (high - low)/2;
        if(v[mid].first.first <= target){
            low = mid + 1;
            ans = mid;
        }
        else{
            high = mid - 1;
        }
    }
    return ans;
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    
    int n;
    cin>>n;
    vector<pair<pair<int,int>,int>> v;  //<<endtime,starttime>, profit>
    int e,s,p;
    for(int i=0;i<n;i++){
		cin>>s>>e>>p;
        v.push_back(make_pair(make_pair(e,s),p));
    }
    
    sort(v.begin(),v.end());
    
    int ptill[n];
    for(int i=0;i<n;i++){
		ptill[i] = v[i].second;
    }
    for(int i=1;i<n;i++){
        ptill[i] = max(ptill[i],ptill[i-1]);
        int k = bsearch(v,0,i-1,v[i].first.second);
        if(v[k].first.first>v[i].first.second){
            continue;
        }
    	ptill[i] = max(ptill[i], v[i].second+ptill[k]);
    }
    //for(int i=0;i<n;i++){
	//	cout<<ptill[i]<<" ";
    //}
    //cout<<endl;
    int answer = ptill[n-1];
    cout<<answer;
    return 0;
}