/*
Harshit gave Aahad an array of size N. He asked Aahad to minimize the difference between the maximum value and minimum value by modifying the array under some condition. The condition is that each array element either increases or decreases by K (only once).
The task seems difficult to Aahad, so he has asked you for your help. Are you up to the challenge?
Input Format:
First line of input contains an integer T, representing the number of test cases.
For each test case, first line contains two space-separated integers: N, K
Next lines contain N space-separated integers denoting elements of the array
Constraints
1 <= T <= 100
1 =< N <= 10^5 
1 <= Ai,K <= 10^9
Output Format
The output contains a single integer denoting the minimum difference between maximum value and the minimum value in the array
Sample Input 1:
1
3 6
1 15 10
Sample Output 1:
5
Explaination
We change from 1 to 6, 15 to  9 and 10 to 4. Maximum difference is 5 (between 4 and 9). We can't get a lower difference.
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll getMinDiff(ll a[],ll n,ll k){
    
    sort(a,a+n);
    ll maxe,mine;
    maxe = a[n-1];
    mine = a[0];
    ll result = maxe - mine;
   	maxe = a[n-1]-k;
    mine = a[0]+k;
    if(mine>maxe){
        ll temp = maxe;
        maxe = mine;
        mine = temp;
    }
    
    for(int i=1;i<n-1;i++){
        ll sub = a[i] - k;
        ll add = a[i] + k;
        if(sub >= mine || add<= maxe){
            continue;
        }
        if(maxe-sub <= add-mine){
            mine = sub;
        }
        else{
            maxe = add;
        }
    }
    result = min(result, maxe - mine);
    return result;
    
}

int main(){
    
    int t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        ll a[n];
        
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        cout<<getMinDiff(a,n,k)<<endl;
    }
    return 0;
}