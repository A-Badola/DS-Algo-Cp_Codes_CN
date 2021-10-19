/*
Gengar has got an integer N. Now using his ghostly powers, he can create the permutation from 1 to N of this given number.
Since, he's a special kind of Poke'mon, so he thinks he deserves special permutations. He wants to find the total number of special permutations of length N, consisting of the integers from 1 to N
.

A permutation is called special if it satisfies following condition:
If Ap & Aq == Ap, then p < q, where p and q are two distinct indices of permutation and A is the permutation itself. "&" denotes the bitwise and operation.
Help Gengar in finding the number of such permutations.
Input format:
The only line of input will consist of a single integer N denoting the length of the permutation.
Output format:
Output the total number of special permutations of length N
.

Constraints:
1 ≤ N ≤ 20

SAMPLE INPUT
4

SAMPLE OUTPUT
8

Explanation
All the special permutations of length 4 are:
1 2 3 4
1 2 4 3
1 4 2 3
2 1 3 4
2 1 4 3
2 4 1 3
4 1 2 3
4 2 1 3

*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll total_permutation(int n,ll mask,ll* mat){
  if(mask == (1<<n) - 1){
    //cout<<endl;
    return 1;
  }

  if(mat[mask] != -1){
    return mat[mask];
  }
  
  ll ans = 0;
  for(int i=1;i<=n;i++){
    bool proceed = true;
    if(!(mask & (1<<(i-1)))){
      for(int j=1;j<=n;j++){ 
        int k = i & j;
        if(i!=j && k==j && !(mask & (1<<(j-1)))) {
          //cout<<"cond  : "<<i<<" "<<j<<" "<<(i & j)<<endl;
          proceed = false;
          break;
        }
      }
      if(proceed){
        //cout<<i<<" ";
        ans = ans + total_permutation(n, mask|(1<<(i-1)), mat); 
      }
    }
  }
  mat[mask] = ans;
  return ans;
}

int main(){
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);

  int n;
  cin>>n;
  ll* mat = new ll[(1<<n)];
  for(int i=0;i<(1<<n);i++){
    mat[i] = -1;
  }
  cout<<total_permutation(n,0,mat); 
  delete[] mat;
  return 0;
}