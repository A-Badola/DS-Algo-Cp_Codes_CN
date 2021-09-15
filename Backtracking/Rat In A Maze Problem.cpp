/*
You are given an integer N and a binary 2D array of size N*N. The given binary matrix represents a maze and a rat starts from the top left cell and has to reach to the bottom right cell of the maze. The rat can move in all the four directions: up, down, left and right.
In the given binary matrix, 0 signifies the cell is a dead end and 1 signifies the cell can be used to move from source to destination cell.
You have to print all the paths, following which rat can move from the top left cell to the bottom right cell of the given binary matrix.
Input Format
The first line of input contains an integer, that denotes the value of N.
Each of the following N lines denote rows of the binary matrix and contains either 0 or 1. Each row of the binary matrix contains N elements. 
Output Format :
Every possible solution has to be printed on a separate line. Each of the possible solution will have N*N elements, printed row wise and separated by space. The cells that are part of the path should be 1 and remaining all cells should be 0. Please refer to sample test cases for more clarity.   
Constraints
1 <= N <= 18
0 <= Number of cells with value 1 <= 15
Time Limit: 1 second
Sample Input 1 :
3
1 0 1
1 0 1
1 1 1
Sample Output 1 :
1 0 0 1 0 0 1 1 1 
Explanation :
Only 1 path is possible. The path is shown in the image below.
*/

#include<bits/stdc++.h>
using namespace std;

int mat[19][19];
void backtrack(int maze[][19],int n,int i,int j){
  if(i<0 || j<0 || i>n-1 || j>n-1){
    return ;
  }
  //cout<<i<<" "<<j<<endl;
  if(i==n-1 && j==n-1){
    mat[i][j] = 1;
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        cout<<mat[i][j]<<" ";
      }
    }
    cout<<endl;
    mat[i][j] = 0;
    return;
  }
  mat[i][j] = 1;
  if(!mat[i-1][j] && maze[i-1][j]){
    backtrack(maze,n,i-1,j);
  }
  if(!mat[i+1][j] && maze[i+1][j]){
    backtrack(maze,n,i+1,j);
  }
  if(!mat[i][j-1] && maze[i][j-1]){
    backtrack(maze,n,i,j-1);
  }
  if(!mat[i][j+1] && maze[i][j+1]){
    backtrack(maze,n,i,j+1);
  }
  mat[i][j] = 0;
  return;
}


int main()
{
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);

  int n;
  cin>>n;
  memset(mat,0,sizeof(mat));
  int maze[19][19];
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin>>maze[i][j];
    }
  }
  int cur_i = 0;
  int cur_j = 0;
  backtrack(maze,n,cur_i,cur_j);
  return 0;
}