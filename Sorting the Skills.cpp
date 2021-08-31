/*
There is a company named James Peterson & Co. The company has ‘n’ employees. The employees have skills, which is denoted with help of an integer. The manager of James Peterson & Co. wants to sort the employees on the basis of their skills in ascending order. He is only allowed to swap two employees which are adjacent to each other. He is given the skills of employees in an array of size ‘n’. He can swap the skills as long as the absolute difference between their skills is 1. You need to help the manager out and tell whether it is possible to sort the skills of employees or not.
Input Format:
First Line will have an integer ‘t’ denoting the no. of test cases.
First line of each test case contains an integer ‘n’ denoting the no. of employees in the company.
Second line of each test case contains ‘n’ integers.
Output Format:
For each test case, print “Yes” if it is possible to sort the skills otherwise “No”.
Constraints:
1 <= t <= 10^4
1 <= n <= 10^5
Sum of n over all test cases doesn't exceed 10^6
Sample Input:
2
4
1 0 3 2
3
2 1 0
Sample Output:
Yes
No
Explanation:
In first T.C., [1, 0, 3, 2] -> [0, 1, 3, 2] -> [0, 1, 2, 3]
In second T.C., [2, 1, 0] -> [1, 2, 0]  OR  [2, 1, 0] -> [2, 0, 1] So, it is impossible to sort.
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool ans = true;
void inmerge(int *a,int n, int m)
{
  int temp[n+m];
  int i=0,j=0,k=0;
  if(a[n-1]-a[n] > 1){
      ans = false;
  }
  while(j<n && k<m){
    if(a[j]<a[n+k]){
      temp[i++] = a[j++]; 
    }
    else if(a[j]>=a[n+k]){
      temp[i++] = a[n+k];
      k++;
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
}

void getSum(int *arr, int s)
{
    if(s>1)
    {
        int n=s/2;
        int m=s-n;
        getSum(arr,n);
        getSum(arr+n,m);
        inmerge(arr,n,m);
        //return x + y + z;
    }
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--){
		int n;
        cin>>n;
        int nums[n];
        for(int i=0;i<n;i++){
            cin>>nums[i];
        }
        
        ans = true;
        getSum(nums,n);
        if(ans){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}