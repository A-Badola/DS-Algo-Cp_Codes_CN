/*
For a given integer array/list 'ARR' of size 'N', find the total number of 'Inversions' that may exist.
An inversion is defined for a pair of integers in the array/list when the following two conditions are met.
A pair ('ARR[i]', 'ARR[j]') is said to be an inversion when:

1. 'ARR[i] > 'ARR[j]' 
2. 'i' < 'j'

Where 'i' and 'j' denote the indices ranging from [0, 'N').
Input format :
The first line of input contains an integer 'N', denoting the size of the array.

The second line of input contains 'N' integers separated by a single space, denoting the elements of the array 'ARR'.
Output format :
Print a single line containing a single integer that denotes the total count of inversions in the input array.
Note:
You are not required to print anything, it has been already taken care of. Just implement the given function.  
Constraints :
1 <= N <= 10^5 
1 <= ARR[i] <= 10^9

Where 'ARR[i]' denotes the array element at 'ith' index.

Time Limit: 1 sec
Sample Input 1 :
3
3 2 1
Sample Output 1 :
3
Explanation of Sample Output 1:
We have a total of 3 pairs which satisfy the condition of inversion. (3, 2), (2, 1) and (3, 1).
Sample Input 2 :
5
2 5 1 3 4
Sample Output 2 :
4
Explanation of Sample Output 1:
We have a total of 4 pairs which satisfy the condition of inversion. (2, 1), (5, 1), (5, 3) and (5, 4).
*/

long long inmerge(long long *a,int n, int m)
{
  int temp[n+m];
  int i=0,j=0,k=0;
  long long count =0;
  while(j<n && k<m){
    if(a[j]<=a[n+k]){
      temp[i++] = a[j++]; 
    }
    else if(a[j]>a[n+k]){
      temp[i++] = a[n+k];
      k++;
      count+=n-j;
    }
  }
  while(j<n){
    temp[i++] = a[j++];
  }
  while(k<m){
    temp[i++]=a[n+k];
    k++;
  }
  for(int i=0;i<n+m;i++){
    a[i] = temp[i];
  }
  return count;
}

long long getInversions(long long *arr, int s)
{
    if(s>1)
    {
        int n=s/2;
        int m=s-n;
        long long x = getInversions(arr,n);
        long long y = getInversions(arr+n,m);
        long long z = inmerge(arr,n,m);
        return x + y + z;
    }
    else{
      return 0;
    }
}