/*
Dwight is always bragging about how amazing he is at solving complicated problems with much ease. Jim got tired of this and gave him an interesting problem to solve.
Jim gave Dwight a sequence of integers a1, a2, ..., an and q queries x1, x2, ..., xq on it. For each query xi Dwight has to count the number of pairs (l, r) such that 1 ≤ l ≤ r ≤ n and GCD(al, al + 1, ..., ar) = xi. Dwight is feeling out of his depth here and asked you to be his Secret Assistant to the Regional Manager. Your first task is to help him solve the problem. Are you up to it?
Input Format:
First line of input contains an integer N, representing the number of elements in the sequence.
Second line contains N space-separated integers denoting the elements of the sequence.
Third line of input contains an integer Q, representing the number of queries.
Next Q line contains an integer X.
Constraints:
1 < = N <= 10^4
1 <= arr[i] <= 10^9
1 <= Q <= 10^4
1 <= X <= 10^9 
Output Format:
For each query, print the answer in a new line.
Sample Input:
2
8 12 
3
8
12
4
Sample Output:
1
1
1
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef map<int,int>:: iterator it;

int gcd(int a,int b){
    if(a<b){
        int temp = a;
        a = b;
        b = temp;
    }
    return b==0? a: gcd(b,a%b);
}


int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    map<int,ll> ans;
    map<int,int> now;
    map<int,int> nxt;
    
    for(int i=0;i<n;i++){
        nxt.clear();
        for(it j = now.begin();j!=now.end();j++){
            nxt[gcd(j->first,a[i])] += j->second;
        }
        nxt[a[i]]++;
        swap(nxt,now);
        for(it j = now.begin();j!=now.end();j++){
            ans[j->first]+= j->second;
        }
    }
    
    int q;
    cin>>q;
    
    while(q--){
        int x;
        cin>>x;
        cout<<ans[x]<<endl;
    }
    return 0;
}