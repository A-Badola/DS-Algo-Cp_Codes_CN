/*
Charlie acquired airline transport company and to stay in business he needs to lower the expenses by any means possible. There are N pilots working for his company (N is even) and N/2 plane crews needs to be made. A plane crew consists of two pilots - a captain and his assistant. A captain must be older than his assistant. Each pilot has a contract granting him two possible salaries - one as a captain and the other as an assistant. A captain's salary is larger than assistant's for the same pilot. However, it is possible that an assistant has larger salary than his captain. Write a program that will compute the minimal amount of money Charlie needs to give for the pilots' salaries if he decides to spend some time to make the optimal (i.e. the cheapest) arrangement of pilots in crews.
Input Format:
First line will contain T(number of test case), each test case as follow.
The first line of each test case contains integer N, N is even, the number of pilots working for the Charlie's company.
The next N lines of input contain pilots' salaries. The lines are sorted by pilot's age, the salaries of the youngest pilot are given the first. Each of those N lines contains two integers separated by a space character, a salary as a captain (X) and a salary as an assistant (Y).
Constraints
1 <= T <= 20
2 ≤ N ≤ 1000
1 ≤ Y < X ≤ 100000
Output Format:
For each test case print the minimal amount of money Charlie needs to give for the pilots' salaries. in newline. 
Sample Input
1
4 
5000 3000 
6000 2000 
8000 1000 
9000 6000 
Sample Output
19000 
*/

#include<bits/stdc++.h>
using namespace std;
int mat[550][550];
int minExp(int* x, int* y, int n, int sz, int cx, int cy){
  if(n==0){
    return mat[cx][cy] = 0;
  }
  int ans;
  if(mat[cx][cy] != -1){
      return mat[cx][cy];
  }
  if(cx>cy && cx<sz/2){
    ans = min(x[n-1] + minExp(x,y,n-1,sz,1+cx,cy), y[n-1] + minExp(x,y,n-1,sz,cx,1+cy));
    mat[cx][cy] = ans;
  }
  else if(cx<sz/2){
    ans =  x[n-1] + minExp(x,y,n-1,sz,1+cx,cy);
    mat[cx][cy] = ans;
  }
  else if(cy<sz/2){
    ans = y[n-1] + minExp(x,y,n-1,sz,cx,1+cy);
    mat[cx][cy] = ans;
  }
  return ans;
}

int main(){
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);

  int t;
  cin>>t;
  while(t--){
	memset(mat,-1,sizeof(mat));
    int n;
    cin>>n;

    int x[n],y[n];
    for(int i=0;i<n;i++){
      cin>>x[i]>>y[i];
    }
    int cx = 0,cy = 0;
    cout<<minExp(x,y,n,n,cx,cy)<<endl;
  }
  return 0;
}