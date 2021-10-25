/*
You are given n activities with their start and finish times. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time.
Input Format
The first line of input contains one integer denoting N.
Next N lines contains two space separated integers denoting the start time and finish time for the ith activity. 
Constraints
1 ≤ N ≤ 10^6
1 ≤ ai, di ≤ 10^9
Output Format
Output one integer, the maximum number of activities that can be performed
Sample Input 1
6
1 2
3 4
0 6
5 7
8 9
5 9
Sample Output 1
4
Explanation:
The four activities will be done at following time intervals:
1. 1 2
2. 3 4
3. 5 7
4. 8 9
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool compare(pair<ll,ll> a, pair<ll,ll> b){
    if(a.second<b.second){
        return true;
    }
    else if(a.second==b.second){
        if(a.first<b.first){
			return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

int main(){
    
    int n;
    cin>>n;
    vector<pair<ll,ll>> t;
    ll s,e;
    for(int i=0;i<n;i++){
        cin>>s>>e;
        t.push_back(make_pair(s,e));
    }
    sort(t.begin(),t.end(),compare);
    ll ans = 1;
    ll last = t[0].second;
    for(int i=1;i<n;i++){
		if(t[i].first >= last){
            ans++;
            last = t[i].second;
        }
    }
    cout<<ans<<endl;
    return 0;
}