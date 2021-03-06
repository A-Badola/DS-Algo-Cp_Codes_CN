/*
Aahad gives an array of integers and asks Harshit to find which three elements form a triangle (non-degenerate). The task seems quite easy to Harshit.
So, Aahad adds some conditions to this task -
1. Find the triangle with maximum perimeter
2. If there are two or more combinations with same value of maximum perimeter, then find the one with the longest side.
3. If there are more than one combinations which satisfy all the above conditions, the find the one with longest minimum side.
Input Format
First line of input contains an integer T, representing the number of test cases.
For each test case, first line contains an integer N, denoting the size of array.
For each test case, the second line contains N space separatated integers, representing the elements of array A[i].
Constraints
1 <= T <= 100
1 =< N <= 10^5 
1 <= A[i] <= 10^8
Time Limit: 1 second
Output Format
The output contains three space-separated elements that denote the length of the sides of triangle. If no such triangle is possible, then print -1.
Sample Input 1:
1
5
1 1 1 3 3
Sample Output 1:
1 3 3 
Explanation
In this case, the elements that form a triangle with maximum perimeter is 1,3,3.
Sample Input 2:
1
3
2 2 4
Sample Output 3:
-1 
Explanation
In this case, the elements that can form a triangle are degenerate, so, we printed -1
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin>>t;
    while(t--){
		ll n;
        cin>>n;
        ll a[n];
        for(int i=0;i<n;i++){
			cin>>a[i];
        }
        sort(a,a+n);
        
        ll ind=-1;
        for(int i=n-1;i-2>=0;i--){
			if(a[i] < a[i-1] + a[i-2]){
                ind = i;
                break;
            }
        }
        if(ind==-1){
            cout<<-1<<endl;
            continue;
        }
        cout<<a[ind-2]<<" "<<a[ind-1]<<" "<<a[ind]<<endl;
    }
    return 0;
}