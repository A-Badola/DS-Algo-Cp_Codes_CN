/*
You have been given a random integer array/list(ARR) and a number X. Find and return the triplet(s) in the array/list which sum to X.
Note :
Given array/list can contain duplicate elements.
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

First line of each test case or query contains an integer 'N' representing the size of the first array/list.

Second line contains 'N' single space separated integers representing the elements in the array/list.

Third line contains an integer 'X'.
Output format :
For each test case, print the total number of triplets present in the array/list.

Output for every test case will be printed in a separate line.
Constraints :
1 <= t <= 10^2
0 <= N <= 10^3
0 <= X <= 10^9

Time Limit: 1 sec
Sample Input 1:
1
7
1 2 3 4 5 6 7 
12
Sample Output 1:
5
Sample Input 2:
2
7
1 2 3 4 5 6 7 
19
9
2 -5 8 -6 0 5 10 11 -3
10
Sample Output 2:
0
5


 Explanation for Input 2:
Since there doesn't exist any triplet with sum equal to 19 for the first query, we print 0.

For the second query, we have 5 triplets in total that sum up to 10. They are, (2, 8, 0), (2, 11, -3), (-5, 5, 10), (8, 5, -3) and (-6, 5, 11)
*/


#include<bits/stdc++.h>
using namespace std;
int tripletSum(int *arr, int n, int num)
{
	sort(arr,arr+n);
    int ans=0;
  
    for(int i=0; i<n-2; i++){
       int cur=num-arr[i];
        int l=i+1,r=n-1;
        while(l<r){
            int cnt1=0,cnt2=0;
            if((arr[l]+arr[r])==cur){
                int temp=arr[l];
                while(l<r and arr[l]==temp){
                    cnt1++;
                    l++;
                }
                if(l==r){
                	if(arr[l-1]==arr[r]){
                        cnt1++;
                        ans+=(cnt1*(cnt1-1))/2;
                        break;
                    }
                   
                }
                temp=arr[r];
                while(r>l-1 and arr[r]==temp){
                    cnt2++;
                    r--;
                }
                ans+=cnt1*cnt2;
               
            }
            else if((arr[l]+arr[r])<cur) l++;
            else r--;
        }
        
    }
    return ans;
}