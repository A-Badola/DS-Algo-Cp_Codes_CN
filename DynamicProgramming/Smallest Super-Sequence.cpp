/*
Given two strings S and T, find and return the length of their smallest super-sequence.
A shortest super sequence of two strings is defined as the shortest possible string containing both strings as subsequences.
Note that if the two strings do not have any common characters, then return the sum of lengths of the two strings.
Input Format:
First line will contain T(number of test case), each test consists of two lines.
Line 1 : A string
Line 2: Another string
Output Format:
Length of the smallest super-sequence of given two strings for each test case in new line.
Constraints:
1 <= T <= 50
1 <= |str1|, |str2| <= 500
Sample Input:
1
ab
ac
Sample Output:
3
Sample Output Explanation:
Their smallest super-sequence can be "abc" which has length=3.
*/

#include<bits/stdc++.h>
using namespace std;
/*
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
*/
int lcs(string& s1, string&s2, int m, int n){
    int mat[m+1][n+1];
    for(int i=0;i<=n;i++){
        mat[0][i] = 0;
    }
    for(int i=0;i<=m;i++){
        mat[i][0] = 0;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s1[i-1]==s2[j-1]){
                mat[i][j] = 1 + mat[i-1][j-1];
            }
            else{
                mat[i][j] = max(mat[i-1][j],mat[i][j-1]);
            }
        }
    }
    return mat[m][n];
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        int m = s1.size();
        int n = s2.size();
        //cout<<s1<<" "<<s2<<" "<<m<<" "<<n<<endl;
        cout<<m + n - lcs(s1,s2,m,n)<<endl;
    }
    return 0;
}