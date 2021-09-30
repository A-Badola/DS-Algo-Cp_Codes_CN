/*
You are given an integer N and asked to find the Xor of first N natural numbers.
Input Format:
The first line of input will contain T(number of test cases), each test case follows as.
The only line of input contains an integer N.
Output Format:
For each test case print the Xor of first N natural number in a new line.
Constraints:
1 <= T <= 10^5
1 <= N <= 10^9
Sample Input:
1 
8
Sample Output:
8
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    
    int t;
    cin>>t;
    while(t--){
		int n;
        cin>>n;
        int ans = 0;
        if(n%4==0){
			ans = n;
        }
        else if(n%4==1){
            ans = 1;
        }
        else if(n%4==2){
            ans = n+1;
        }
        else {
            ans = 0;
        }
        cout<<ans<<endl;
    }
    return 0;
}

/*
What you can think for this kind of situation is ... analyze the output for some value using basic methoc and then find the logic or pattern. 
So first what I did was, 

#include<bits/stdc++.h>
using namespace std;
int main(){
    
    int t;
    cin>>t;
    while(t--){
		int n;
        cin>>n;
        int k=1;
        for(int i=2;i<=n;i++){
            k = k^i;
        }
        cout<<k<<endl;
    }
    return 0;
}
*/