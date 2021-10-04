/*
Given two strings s and t of lengths m and n respectively, find the Edit Distance between the strings. Edit Distance of two strings is minimum number of steps required to make one string equal to other. In order to do so you can perform following three operations only :
1. Delete a character

2. Replace a character with another one

3. Insert a character
Note - Strings don't contain spaces
Input Format :
First line of input will contain T (number of test cases), each test case consists of two lines.
Line 1 : String s
Line 2 : String t
Output Format :
For each test case print the Edit Distance value in new line.
Constraints:
1 <= T <= 100
1<= m,n <= 100
Sample Input 1 :
1
abc
dc
Sample Output 1 :
2
*/

#include<bits/stdc++.h>
using namespace std;

int mat[105][105];

int eds(string& s1,string& s2, int m, int n){
    //cout<<s1<<" "<<m<<" "<<s2<<" "<<n<<endl;
    if(m==0 || n==0){
      return mat[m][n] = m==0?n:m;
    }
	if(mat[m][n]!=-1){
        return mat[m][n];
    }
    if(s1[m-1] == s2[n-1]){
        return mat[m][n] = eds(s1,s2,m-1,n-1);
    }
    else{
		return mat[m][n] = 1 + min(eds(s1,s2,m-1,n-1),min(eds(s1,s2,m-1,n),eds(s1,s2,m,n-1)));
    }
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--){
        memset(mat,-1,sizeof(mat));
        string s1,s2;
        cin>>s1>>s2;
        int m = s1.size();
        int n = s2.size();
        cout<<eds(s1,s2,m,n)<<endl;
    }
    return 0;
}