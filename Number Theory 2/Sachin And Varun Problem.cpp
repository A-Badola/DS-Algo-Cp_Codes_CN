/*
Varun and you are talking about a movie that you have recently watched while Sachin is busy teaching Number Theory. Sadly, Sachin caught Varun talking to you and asked him to answer his question in order to save himself from punishment. The question says:
Given two weights of a and b units, in how many different ways you can achieve a weight of d units using only the given weights? Any of the given weights can be used any number of times (including 0 number of times).
Since Varun is not able to answer the question, he asked you to help him otherwise he will get punished.
Note: Two ways are considered different if either the number of times a is used or a number of times b is used is different in the two ways.
Input Format:
The first line of input consists of an integer 
T denoting the number of test cases.
Each test case consists of only one line containing three space-separated integers a, b and d.
Output Format:
For each test case, print the answer in a separate line.
Constraints:
1 ≤ T ≤ 10 ^ 5

1 ≤ a < b ≤ 10 ^ 9

0 ≤ d ≤ 10 ^ 9
Sample Input 1
4
2 3 7
4 10 6
6 14 0
2 3 6
Sample Output 1
1
0
1
2
Explanation
Test case 1: 7 can only be achieved by using 2 two times and 3 one time.

Test case 2: 6 can't be achieved by using 4 and 10. So, 0 ways are there.
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


ll gcd(int a, int b){ if(b==0){return a;} return gcd(b,a%b);} 

class triplet{
  public:
    ll x;
    ll y;
    ll gcd;
};

triplet extendedEuclid(ll a, ll b){
  //base case
  if(b==0){
    triplet ans;
    ans.x = 1;
    ans.y = 0;
    ans.gcd = a;
    return ans;
  }

  //extendedEuclid Algo
  triplet smallAns = extendedEuclid(b,a%b);
  triplet ans;
  ans.gcd = smallAns.gcd;
  ans.x = smallAns.y;
  ans.y = smallAns.x - (a/b)*smallAns.y;
  return ans;
}


int main(){
    
    // write your code here
    ll t;
    cin>>t;
    while(t--){
		ll a,b,d;
        cin>>a>>b>>d;
        ll g = gcd(a,b);
		    if(d%g){
            cout<<0<<endl;
            continue;
        }
        if(d==0){
            cout<<1<<endl;
            continue;
        }
        a = a/g;
        b = b/g;
        d = d/g;
        triplet gety1 = extendedEuclid(b,a);
    	  ll y1 = ((d%a)*(gety1.x%a + a)%a)%a;
        if(d<b*y1){
            cout<<0<<endl;
            continue;
        }
        ll n = ((d/b) - y1)/a;
        ll ans = n + 1;
        cout<<ans<<endl;
    }
    return 0;
}  