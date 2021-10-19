/*
Given an array of n positive integers. The task is to count the number of Arithmetic Progression subsequences in the array. As the answer could be very large, output it modulo 10^9 + 7.
Note: Empty sequence or single element sequence is Arithmetic Progression.
Input Format:
First Line: N (the size of the array)
Second Line: Elements of the array separated by spaces.
Output:
 Print total number of subsequences
Input Constraints:
1 <= arr[i] <= 1000
1 <= sizeof(arr) <= 1000
Sample Input 1 :
3
1 2 3
Sample output:
8
Sample Output Explanation:
Total subsequence are: {}, { 1 }, { 2 }, { 3 }, { 1, 2 }, { 2, 3 }, { 1, 3 }, { 1, 2, 3 }
Sample Input 2:
7
1 2 3 4 5 9 10
Sample Output:
37
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const unsigned int M = 1000000007;

int numofAP(int* arr, int n){
  ll ans = n+1; //all the individual element form AP including {} 
  
  unordered_map<int,int> mat[n];
  //initializing with pairs subsequences - all pairs form AP
  for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
      ll diff = arr[j] - arr[i];
      mat[i][diff] = (mat[i][diff] + 1)%M;
      ans = (ans + 1)%M;
    }
  }

  for(int i=n-3;i>=0;i--){
    for(int j=i+1;j<n;j++){
      ll diff = arr[j] - arr[i];
      mat[i][diff] = (mat[i][diff]%M + mat[j][diff]%M)%M;
      ans = (ans%M + mat[j][diff]%M)%M;
    }
  }

  return ans ;
}

int main(){
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);

  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }

  cout<<numofAP(arr,n);
}