/*
Coding Ninjas has provided you a crossword of 10*10 grid. The grid contains '+' or '-' as its cell values. Now, you are also provided with a word list that needs to placed accurately in the grid. Cells marked with '-' are to be filled with word list.
For example, The following is an example for the input crossword grid and the word list.
+-++++++++
+-++-+++++
+-------++
+-++-+++++
+-++-+++++
+-++-+++++
++++-+++++
++++-+++++
++++++++++
----------
CALIFORNIA;NIGERIA;CANADA;TELAVIV
Output for the given input should be:
+C++++++++
+A++T+++++
+NIGERIA++
+A++L+++++
+D++A+++++
+A++V+++++
++++I+++++
++++V+++++
++++++++++
CALIFORNIA
Note: We have provided such test cases that there is only one solution for the given input.
Input format:
The first 10 lines of input contain crossword. Each of 10 lines has a character array of size 10. Input characters are either '+' or '-'.
The next line of input contains the word list, in which each word is separated by ';'. 
Output format:
Print the crossword grid, after placing the words of word list in '-' cells.  
Constraints
The number of words in the word list lie in the range of: [1,6]
The length of words in the word list lie in the range: [1, 10]
Time Limit: 1 second
Sample Input 1:
+-++++++++
+-++-+++++
+-------++
+-++-+++++
+-++-+++++
+-++-+++++
++++-+++++
++++-+++++
++++++++++
----------
CALIFORNIA;NIGERIA;CANADA;TELAVIV
Sample Output 1:
+C++++++++
+A++T+++++
+NIGERIA++
+A++L+++++
+D++A+++++
+A++V+++++
++++I+++++
++++V+++++
++++++++++
CALIFORNIA
*/

#include<bits/stdc++.h>
using namespace std;
#define N 10
#define endl "\n"
typedef vector<string> vs;

bool getpos(char grid[][N],int& row, int& col){
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(grid[i][j]=='-'){
        row = i;
        col = j;
        return true;
      }
    }
  }
  return false;
}

bool canRowwise(char grid[][N],int row,int col,string word){
  //cout<<"check row "<<word<<endl;
  int i=row;
  int j=col;
  //cout<<row<<" "<<col<<endl;
  int rlen = 0;
  if(col>0 && grid[row][col-1]!='+'){
  if(grid[row][col-1]==word[0]){
    rlen++;
  }
  else{
    return false;
  }
  }
  while(j<N && (grid[i][j] == '-')){
    j++;
    rlen++;
    while(j<N && grid[i][j]==word[rlen]){
      j++;
      rlen++;
    }
  }
  if(rlen == word.size()){
    return true;
  }
  return false;
}

bool canColwise(char grid[][N],int row,int col,string word){
  //cout<<"check col "<<word<<endl;
  int i=row;
  int j=col;
  int clen = 0;
  if(row>0 && grid[row-1][col]!='+'){
  if(grid[row-1][col]==word[0]){
    clen++;
  }
  else{
    return false;
  }
  }
  while(i<N && grid[i][j] == '-'){
    i++;
    clen++;
    while(i<N && grid[i][j]==word[clen]){
      i++;
      clen++;
    }
  }
  if(clen == word.size()){
    return true;
  }
  return false;
}

void writeRowwise(char grid[][N],int row,int col,string word){
  //cout<<"write Row "<<word<<endl;
  int i=row;
  int j=col;
  int wi=0;
  if(col>0 && grid[row][col-1]==word[0]){
    wi++;
  }
  while(wi<word.size()){
    grid[i][j++] = word[wi++];
  }
}


void writeColwise(char grid[][N],int row,int col,string word){
  //cout<<"write Col "<<word<<endl;
  int i=row;
  int j=col;
  int wi=0;
  if(row>0 && grid[row-1][col]==word[0]){
    wi++;
  }
  while(wi<word.size()){
    grid[i++][j] = word[wi++];
  }
}

void eraseRowwise(char grid[][N],int row,int col,string word){
  //cout<<"erase Row "<<word<<endl;
  int i = row;
  int j = col;
  int len = 0;
  int wlen = word.size();
  if(col>0 && grid[row][col-1]==word[0]){
    len++;
  }
  while(len < wlen){
    grid[i][j++] = '-';
    len++;
  }
}

void eraseColwise(char grid[][N],int row,int col,string word){
  //cout<<"erase col "<<word<<endl;
  int i = row;
  int j = col;
  int len = 0;
  int wlen = word.size();
  if(row>0 && grid[row-1][col]==word[0]){
    len++;
  }
  while(len < wlen){
    grid[i++][j] = '-';
    len++;
  }
}

bool crosswordSolver(char grid[][N],vs words, bool wordUsed[]){
  int row,col;
  if(!getpos(grid,row,col)){
    return true;
  }

  for(int i=0;i<words.size();i++){
    if(!wordUsed[i] && canRowwise(grid,row,col,words[i])){
      writeRowwise(grid,row,col,words[i]);
      wordUsed[i]=1;
      if(crosswordSolver(grid,words,wordUsed)){
        return true;
      }
      else{
        eraseRowwise(grid,row,col,words[i]);
        wordUsed[i] = 0;
      }
    }
    if(!wordUsed[i] && canColwise(grid,row,col,words[i])){
      writeColwise(grid,row,col,words[i]);
      wordUsed[i]=1;
      if(crosswordSolver(grid,words,wordUsed)){
        return true;
      }
      else{
        eraseColwise(grid,row,col,words[i]);
        wordUsed[i] = 0;
      }
    }
  }
  return false;
}
int main(){
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);

  char grid[N][N];

  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cin>>grid[i][j];
    }
  }
  string wordlistin;
  cin>>wordlistin;
  vs words;
  int numWords = 0;
  string temp="";
  for(int i=0;i<wordlistin.size();i++){
    numWords++;
    while(i<wordlistin.size() && wordlistin[i]!=';'){
      temp += wordlistin[i];
      i++;
    }
    words.push_back(temp);
    temp="";
  }
  /*for(int i=0;i<numWords;i++){
    cout<<words[i]<<endl;
  }*/
  bool wordUsed[numWords];
  memset(wordUsed,0,sizeof(wordUsed));
  crosswordSolver(grid,words,wordUsed);

  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cout<<grid[i][j];
    }
    cout<<endl;
  }
}
