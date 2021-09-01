/*
You are given an integer h, find and print the count of all possible balanced binary trees of height h.
This number can be huge, so return the output modulus 10^9 + 7.
Input Format :
The first line of input contains an integer, that denotes the value of the number of test cases. Let us denote it with the symbol T.
Each test case consists of a single integer h, that denotes height of the binary tree, in a separate line.
Output Format :
For each test case, there is a single line of output, which prints the count of all possible balanced binary trees of height h, modulus 10^9 + 7. The output for each test case is printed in a separate line.
Constraints :
1 <= T <= 10
1 <= h <= 20
Time Limit: 1 second
Sample Input 1:
1
2
Sample Output 1:
3    
Explanation:
Following are the three balanced binary trees, that can be formed with height = 2.
Alt Text

Sample Input 2:
2
3
4
Sample Output 2:
15
315
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const unsigned int M = 1000000007;

ll numofBT(int n){
  if(n==0||n==1){
    return 1;
  }
  ll x = numofBT(n-1);
  ll y = numofBT(n-2);

  return (((x%M)*(x%M))%M + ((x%M)*(y%M))%M + ((x%M)*(y%M))%M)%M;
}


int main()
{
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);

  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    cout<<numofBT(n)<<endl;
  }
  return 0;
}