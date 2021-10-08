/*
Given two strings S1 and S2 with lengths M and N respectively, find the length of the longest common subsequence.
A subsequence of a string S whose length is K, is a string containing characters in same relative order as they are present in S, but not necessarily contiguous. Subsequences contain all the strings of length varying from 0 to K. For example, subsequences of string "abc" are -- ""(empty string), a, b, c, ab, bc, ac, abc.
Input Format :
First line will contain T(number of test case), each test case will consist of two lines.
Line 1: String S1
Line 2: String s2
Output Format :
Length of the longest common subsequence for each test case in a newline.
Constraints :
1 <= T <= 100
1 <= M <= 100
1 <= N <= 100

Time Limit: 1 sec
Sample Input 1:
1
adebc
dcadb
Sample Output 1:
3
Explanation of Sample Input 1:
"a", "d", "b", "c", "ad", "ab", "db", "dc" and "adb" are present as a subsequence in both the strings in which "adb" has the maximum length. There are no other common subsequence of length greater than 3 and hence the answer.
Sample Input 2:
1
abcd
acbdef
Sample Output 2:
3
Explanation of Sample Input 2:
"a", "b", "c", "d", "ab", "ac", "ad", "bd", "cd", "abd" and "acd" are present as a subsequence in both the strings S1 and S2 in which "abd" and "acd" are of the maximum length. There are no other common subsequence of length greater than 3 and hence the answer.
*/

#include<bits/stdc++.h>
using namespace std;

int mat[105][105];
int lcs(string& s1,string& s2, int m, int n){
    if(m==0 || n==0){
        return mat[m][n] = 0;
    }
    if(mat[m][n] != -1){
        return mat[m][n];
    }
    if(s1[m-1] == s2[n-1]){
        return mat[m][n] = 1 + lcs(s1,s2,m-1,n-1);
    }
    else{
		return mat[m][n] = max(lcs(s1,s2,m,n-1),lcs(s1,s2,m-1,n));
    }
}

int main(){
    
    int t;
    cin>>t;
    while(t--){
        memset(mat,-1,sizeof(mat));
        string s1,s2;
        cin>>s1>>s2;
        int m = s1.size();
        int n = s2.size();
        //cout<<s1<<" "<<s2<<" "<<m<<" "<<n<<endl;
        cout<<lcs(s1,s2,m,n)<<endl;
    }
    return 0;
}