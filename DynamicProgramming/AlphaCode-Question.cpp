//<R>
/*
Alice and Bob need to send secret messages to each other and are discussing ways to encode their messages:
Alice: “Let’s just use a very simple code: We’ll assign ‘A’ the code word 1, ‘B’ will be 2, and so on down to ‘Z’ being assigned 26.”

Bob: “That’s a stupid code, Alice. Suppose I send you the word ‘BEAN’ encoded as 25114. You could decode that in many different ways!”

Alice: “Sure you could, but what words would you get? Other than ‘BEAN’, you’d get ‘BEAAD’, ‘YAAD’, ‘YAN’, ‘YKD’ and ‘BEKD’. I think you would be able to figure out the correct decoding. And why would you send me the word ‘BEAN’ anyway?”

Bob: “OK, maybe that’s a bad example, but I bet you that if you got a string of length 5000 there would be tons of different decodings and with that many you would find at least two different ones that would make sense.”

Alice: “How many different decodings?”

Bob: “Jillions!”
For some reason, Alice is still unconvinced by Bob’s argument, so she requires a program that will determine how many decodings there can be for a given string using her code.
Input Format:
First line will contain T (number of test case).
Each input is consists of a single line containing the message string
Output Format:
For each test case print the answer % mod (10^9 +7)
Constraints:
1 <= T <= 100
1 <= |S| <= 10^5
sum of length of all string doesn't exceed 5*10^6
Sample Input 1:
2
47974
6349988978
1001
Sample Output 1:
1
1
0
*/

#include<bits/stdc++.h>
using namespace std;

const unsigned int M = 1000000007;

long long numCodes(string& s,int n,long long* mat){    
  if(n==0||n==1){
	 mat[n] = 1;
    return mat[n];
  }
  if(mat[n]!=-1){
    return mat[n];
  }
  long long output = numCodes(s,n-1,mat)%M;

  if((s[n-2]-'0')*10 + (s[n-1]-'0') <= 26){
    output = output + (numCodes(s,n-2,mat))%M;
  }
  mat[n] = output%M;
  return mat[n];
}

int main()
{

  int t;
  cin>>t;
  while(t--){
    string s;
    cin>>s;
    int n = s.size();
    long long* mat = new long long[n+1];
    for(int i=0;i<n+1;i++){
        mat[i]=-1;
    }
    bool dec = true;
    for(int i=0;i<n;i++){
        if(s[0]=='0' || s[i]=='0' && s[i-1]=='0' ){
			dec = false;
            break;
        }
    }
    if(dec){
    	cout<<numCodes(s,n,mat)<<endl;
    }
    else{
     	cout<<0<<endl;   
    }
    delete[] mat;
  }
  return 0;
}