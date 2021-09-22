//R
/*
Vanya has been studying all day long about sequences and other Complex Mathematical Terms. She thinks she has now become really good at it. So, her friend Vasya decides to test her knowledge and keeps the following challenge it front of her:
Vanya has been given an integer array A of size N. Now, she needs to find the number of increasing sub-sequences of this array with length ≥1 and GCD=1. A sub-sequence of an array is obtained by deleting some (or none) elements and maintaining the relative order of the rest of the elements. As the answer may be large, print it Modulo 109+7
She finds this task really easy, and thinks that you can do it too. Can you?
Input Format:
First line will contain T(number of test case), each test consists of two line.
The first line contains a single integer N denoting size of array A. 
The next line contains N space separated integers denoting the elements of array A
Output Format:
Print the required answer Modulo 10^9+7 for each test case in new line
Constraints:
1 <= T <= 50
1 <= N <= 200
1 <= A[i] <= 100
Sample Input
1
3
1 2 3
Sample Output
5
*/

#include<bits/stdc++.h>
using namespace std;

const unsigned int M = 1000000007;
long long mat[205][105];
int gcd(int a, int b) { if(a<b){ int temp = a; a=b; b=temp;}return b == 0 ? a : gcd(b, a % b); }

int numSeq(int* num,int n){
  for(int i=0;i<n;i++){
    mat[i][num[i]]=1;
  }
  long long ans = 0;
  for(int i=1;i<n;i++){
    for(int j=i-1;j>=0;j--){
      if(num[j]<num[i]){
        for(int k=1;k<=100;k++){
          if(mat[j][k]>0){
            mat[i][gcd(num[i],k)]+=mat[j][k];
          }
        }
      }
    }
  }
  /*
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cout<<mat[i][j]<<" ";
    }
    cout<<endl;
  }
  */
  for(int i=0;i<n;i++){
    ans = ans + mat[i][1]%M;
  }
  return ans%M;
}

int main(){
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);

  int t;
  cin>>t;
  while(t--){
    memset(mat,0,sizeof(mat));
    int n;
    cin>>n;

    int* num = new int[n];
    for(int i=0; i<n; i++){
      cin>>num[i];
    }
    /*
    for(int i=0;i<n;i++){
      cout<<num[i]<<" ";
    }
    cout<<endl;
    */
    cout<<numSeq(num,n)<<endl;
    delete[] num;
  }
  return 0;
}