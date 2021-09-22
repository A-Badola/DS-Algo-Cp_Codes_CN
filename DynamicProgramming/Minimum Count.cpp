//R
/*
Given an integer N, find and return the count of minimum numbers, sum of whose squares is equal to N.
That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. Output will be 1, as 1 is the minimum count of numbers required.
Note : x^y represents x raise to the power y.
Input Format :
First line will contain T(number of test case), each test case consists of a single line containing an integer N.
Output Format :
For each test case print the required minimum count in a newline.
Constraints :
 1 <= T <= 1000
 1 <= N <= 1000
Sample Input 1 :
1
12
Sample Output 1 :
3
Sample Output 1 Explanation :
12 can be represented as :
1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1
1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 2^2
1^1 + 1^1 + 1^1 + 1^1 + 2^2 + 2^2
2^2 + 2^2 + 2^2
As we can see, the output should be 3.
Sample Input 2 :
1
9
Sample Output 2 :
1
*/

#include<bits/stdc++.h>
using namespace std;

int mat[33][1005];
int minCount(int arr[],int sqn,int val){
  if(sqn==0){
    return mat[sqn][val] = INT_MAX;
  }
  if(val==0){
    return mat[sqn][val] = 0;
  }
  if(mat[sqn][val]!=-1){
      return mat[sqn][val];
  }
  int ans=0;
  if(val-arr[sqn]>=0){
    ans = min(1 + minCount(arr,sqn,val-arr[sqn]),minCount(arr,sqn-1,val));
  }
  else{
    ans = minCount(arr,sqn-1,val);
  }
  return mat[sqn][val] = ans;
}

int solve(int n,int sqn,int* sq){
  int ans = 0;
  int arr[sqn+1]={0};
  for(int i=1;i<=sqn;i++){
    arr[i] = sq[i];
  }
  ans = minCount(arr,sqn,n);
}
int main()
{
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  
  int t;
  cin>>t;
  int sq[33]={0};
  for(int i=1;i<=32;i++){
    sq[i] = i*i;
  }
  while(t--){
    memset(mat,-1,sizeof(mat));
    int n;
    cin>>n;
    int sqn = sqrt(n);
    cout<<solve(n,sqn,sq)<<endl;
  }
  return 0;
}