/*
You are given N, and for a given N x N chessboard, find a way to place N queens such that no queen can attack any other queen on the chess board. A queen can be killed when it lies in the same row, or same column, or the same diagonal of any of the other queens. You have to print all such configurations.
Note: Don't print anything if there isn't any valid configuration.
Input Format:
The first line of input contains an integer, that denotes the value of N.     
Output Format :
In the output, you have to print every board configuration in a new line. Every configuration will have N*N board elements printed row wise and are separated by space. The cells where queens are safe and placed, are denoted by value 1 and remaining all cells are denoted by value 0. Please refer to sample test cases for more clarity.
Constraints :
1 <= N <= 10
Time Limit: 1 second
Sample Input 1:
4
Sample Output 1 :
0 1 0 0 0 0 0 1 1 0 0 0 0 0 1 0 
0 0 1 0 1 0 0 0 0 0 0 1 0 1 0 0 
Explanation:
The first and second configuration are shown in the image below. Here, 1 denotes the placement of a queen and 0 denotes an empty cell. Please note that in both the configurations, no pair of queens can kill each other. 
*/

#include<bits/stdc++.h>
using namespace std;

bool checkPlace(int column[],int r,int c){
  for(int prev = 0; prev < r; prev++){
    if(column[prev]==c || abs(column[prev]-c)==abs(prev - r)){
      return false;
    }
  }
  return true;
}

void backtrack(int column[],int r,int n){
  if(r==n){
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if(column[i]==j){  //jth column of ith row contains queen
          cout<<1<<" ";
        }
        else{
          cout<<0<<" ";
        }
      }
    }
    cout<<endl;
  }

  for(int c = 0 ; c < n; c++){
    if(checkPlace(column,r,c)){
      column[r] = c;
      backtrack(column,r + 1,n);
    }
  }
}
int main()
{
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  int n;
  cin>>n;
  int column[n];  //column jth of row ith 
  memset(column,0,sizeof(column));
  backtrack(column,0,n);
  return 0;
}