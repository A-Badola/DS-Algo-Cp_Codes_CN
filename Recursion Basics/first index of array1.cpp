/*

Given an array of length N and an integer x, you need to find and return the first index of integer x present in the array. Return -1 if it is not present in the array.
First index means, the index of first occurrence of x in the input array.
Do this recursively. Indexing in the array starts from 0.
Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces
Line 3 : Integer x
Output Format :
first index or -1
Constraints :
1 <= N <= 10^3
Sample Input :
4
9 8 10 8
8
Sample Output :
1

*/

int min(int a, int b){
    if(a<=b){
        return a;
    }
    else{
        return b;
    }
}

int firstIndex(int input[], int size, int x) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */

	  if(size==0){
        return -1;
      }
		
      int temp = firstIndex(input,size-1,x);
      if(input[size - 1]==x){
        if(temp!=-1)
        	return min(size - 1, temp);
        else
            return size-1;
      }
      else{
        return temp;
      }
}
