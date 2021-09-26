/*
Noor is a teacher. She wants to give some chocolates to the students in her class. All the students sit in a line and each of them has a score according to performance. Noor wants to give at least 1 chocolate to each student. She distributes chocolates to them such that If two students sit next to each other then the one with the higher score must get more chocolates. Noor wants to save money, so she wants to minimise the total number of chocolates.
Note that when two students have equal score they are allowed to have different number of chocolates.
Input Format:
First line will contain T(number of test case), each test case consists of two lines.
First Line: Integer N, the number of students in Noor’s class. 
Second Line: Each of the student's score separated by spaces.
Output Format:
Output the minimum number of chocolates Noor must give for each test case in a newline.
Input Constraints
1 <= T <= 50
1 <= N <= 50000
1 <= score <= 10^9
Sample Input:
1
4
1 4 4 6
sample Output:
6
Sample Input:
1
3
8 7 5
sample Output:
6
*/

#include<bits/stdc++.h>
using namespace std;

int minChoco(int ar[],int n){
  int inc[n];
  int incr[n];
  inc[0] = 1;
  for(int i=1;i<n;i++){
    if(ar[i]>ar[i-1]){
      inc[i]=inc[i-1] + 1;
    }
    else{
      inc[i] = 1;
    }
  }
  incr[n-1] = 1;
  for(int i=n-2;i>=0;i--){
    if(ar[i]>ar[i+1]){
      incr[i] = incr[i+1] + 1;
    }
    else{
      incr[i] = 1;
    }
  }

  int mx = 0;
  for(int i=0;i<n;i++){
    mx = mx + max(inc[i],incr[i]);
  }
  return mx;
}

int main(){
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);

  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++){
      cin>>ar[i];
    }
    cout<<minChoco(ar,n)<<endl;;
  }
}

/*
BottomUp
#include<bits/stdc++.h>
using namespace std;

int minChoco(int ar[],int n){
  int inc[n];
  inc[0] = 1;
  for(int i=1;i<n;i++){
    if(ar[i]>ar[i-1]){
      inc[i]=inc[i-1] + 1;
    }
    else{
      inc[i] = 1;
    }
  }
  for(int i=n-2;i>=0;i--){
    if(ar[i]>ar[i+1] && inc[i]<=inc[i+1]){
      inc[i] = inc[i+1] + 1;
    }
  }

  int mx = 0;
  for(int i=0;i<n;i++){
    mx = mx + inc[i];
  }
  return mx;
}

int main(){
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);

  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++){
      cin>>ar[i];
    }
    cout<<minChoco(ar,n)<<endl;;
  }
}
*/