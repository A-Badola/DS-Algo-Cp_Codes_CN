/*
Given a string S, remove consecutive duplicates from it recursively.
Input Format :
First line of input will contain T number of test cases
Next T line will contain the string S
Output Format :
For every test case print the answer in a separate line
Constraints :
1 <= T <= 10
1 <= |S| <= 10^4
where |S| represents the length of string
Sample Input 1 :
1
aabccba
Sample Output 1 :
abcba
Sample Input 2 :
1
xxxyyyzwwzzz
Sample Output 2 :
xyzwz
*/

#include<bits/stdc++.h>
using namespace std;

string removeConsecutiveDuplicates(string s,int n){
    if(n==0){
        return "";
    }
    string ans="";
    if(s[n-1] == s[n-2]){
		ans = removeConsecutiveDuplicates(s,n-1);    
    }
    else{
        ans = s[n-1]+removeConsecutiveDuplicates(s,n-1);
    }
    return ans;
}

int main(){
    
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
    	int n = s.size();
        string ans = removeConsecutiveDuplicates(s,n);
        reverse(ans.begin(),ans.end());
        cout<<ans<<endl;
    }
    return 0;
}