//R
/*
A thief wants to loot houses. He knows the amount of money in each house. He cannot loot two consecutive houses. Find the maximum amount of money he can loot.
Input Format :
The first line of input contains a single integer N denoting the total number of houses.

The second line of input contains N single space-separated integers, denoting the amount of money in every i-th house.
Output Format :
The only line of output will print the maximum amount of loot that is possible.
Input Constraints
0 <= N <= 10^5
0 <= A[i] <= 10^4

Where N is the total number of houses.
A[i] represents the money present in the i-th house.

Time limit: 1sec
Sample Input 1:
6
5 5 10 100 10 5
Sample Output 1 :
110
Sample Input 2:
4
10 2 3 11
Sample Output 2 :
21
Explanation to Sample Input 2:
Since the thief cant loot two consecutive houses, the ways in which he may loot are:

1. [10, 3]: a total loot of 13
2. [10, 11]: a total loot of 21
3. [2, 11]: a total loot of 13
4. [10]: a total loot of 10
5. [2]: a total loot of 2
6. [3]: a total loot of 3
7. [11]: a total loot of 11

We can't neglect the option to loot just either of the houses if it yields the maximum loot.

From all the possible seven ways, the second option yields the maximum loot amount and hence the answer.
*/

#include<bits/stdc++.h>
using namespace std;

long long max_loot(int* money,int n,int* mat){
  if(n<1){
    return 0;
  }
  if(n==1||n==2){
    return mat[n-1]=money[n-1];
  }
  if(mat[n-1]!=-1){
      return mat[n-1];
  }
  long long option1 = max_loot(money,n-2,mat);
  long long option2 = max_loot(money,n-3,mat);
  return mat[n-1] = max(option1 + money[n-1],option2 + money[n-1]);
}
int main(){
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);

  int n;
  cin>>n;
  int* money = new int[n];
  for(int i=0;i<n;i++){
    cin>>money[i];
  }
  int *mat = new int[n];
  for(int i=0;i<n;i++){
	mat[i] = -1;
  }
  long long one = max_loot(money,n,mat);
  long long two = max_loot(money,n-1,mat);
  cout<<max(one,two);
  return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;

long long max_loot(int* money,int n,int* mat){
  if(n<1){
    return 0;
  }
  if(n==1){
    return mat[n-1]=money[n-1];
  }
  if(mat[n-1]!=-1){
      return mat[n-1];
  }
  long long option1 = max_loot(money,n-2,mat);
  long long option2 = max_loot(money,n-1,mat);
  return mat[n-1] = max(option1 + money[n-1],option2);
}
int main(){
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);

  int n;
  cin>>n;
  int* money = new int[n];
  for(int i=0;i<n;i++){
    cin>>money[i];
  }
  int *mat = new int[n];
  for(int i=0;i<n;i++){
  mat[i] = -1;
  }
  long long one = max_loot(money,n,mat);
  cout<< one;
  return 0;
}
*/