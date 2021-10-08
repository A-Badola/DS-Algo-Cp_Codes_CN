/*
Given a 2D array, find the maximum sum rectangle in it. In other words find maximum sum over all rectangles in the matrix.
Input Format:
First line of input will contain T(number of test case), each test case follows as.
First line contains 2 numbers n and m denoting number of rows and number of columns. Next n lines contain m space separated integers denoting elements of matrix nxm.
Output Format:
Output a single integer, maximum sum rectangle for each test case in a newline.
Constraints
1 <= T <= 50
1<=n,m<=100
-10^5 <= mat[i][j] <= 10^5
Sample Input
1
4 5
1 2 -1 -4 -20
-8 -3 4 2 1
3 8 10 1 3
-4 -1 1 7 -6
Sample Output
29
*/


#include<bits/stdc++.h>
using namespace std;

int kadane(int v[], int n){
  int sum = 0;
  int ans = INT_MIN;
  for(int i=0;i<n;i++){
    sum = sum + v[i];
    ans = max(ans,sum);
    if(sum<0){
      sum = 0;
    }
  }
  return ans;
}

int main(){
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);

  int t;
  cin>>t;

  while(t--){
    int n,m;
    cin>>n>>m;
    int a[n][m];
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        cin>>a[i][j];
      }
    }

    int v[n];
    int mxRect = INT_MIN;
    for(int i=0;i<m;i++){
      for(int l=0;l<n;l++){
        v[l] = 0;
      }
      for(int j=i;j<m;j++){
        for(int k=0;k<n;k++){
          v[k] = v[k] + a[k][j];
        }
        int subRect = kadane(v,n);
        if(subRect > mxRect){
          mxRect = subRect;
        }
      }
    }
    cout<<mxRect<<endl;
  }
  return 0;
}