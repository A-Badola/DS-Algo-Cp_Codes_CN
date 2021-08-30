/*
Once detective Saikat was solving a murder case. While going to the crime scene he took the stairs and saw that a number is written on every stair. He found it suspicious and decides to remember all the numbers that he has seen till now. While remembering the numbers he found that he can find some pattern in those numbers. So he decides that for each number on the stairs he will note down the sum of all the numbers previously seen on the stairs which are smaller than the present number. Calculate the sum of all the numbers written on his notes diary.
Answer may not fit in integer . You have to take long.
Input Format:
First line of input contains an integer T, representing number of test case.
For each test case, first line of input contains integer N, representing the number of stairs.
For each test case, second line of input contains N space separated integers, representing numbers written on the stairs.
Constraints
T<=10^5
1<=N<=10^5
All numbers will be between 0 and 10^9
Sum of N over all test cases doesn't exceed 5*10^5
Output Format
For each test case output one line giving the final sum for each test case.
Sample Input 1:
1
5
1 5 3 6 4
Sample Output 1:
15
Explanation:
For the first number, the contribution to the sum is 0.
For the second number, the contribution to the sum is 1.
For the third number, the contribution to the sum is 1.
For the fourth number, the contribution to the sum is 9 (1+5+3).
For the fifth number, the contribution to the sum is 4 (1+3).
Hence the sum is 15 (0+1+1+9+4).
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

long long ans = 0;
long long inmerge(long long *a,int n, int m)
{
  int temp[n+m];
  int i=0,j=0,k=0;
  ll count = 0;
  while(j<n && k<m){
    if(a[j]<a[n+k]){
      count+= (m - k)*a[j];
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
  return count;
}

long long getSum(long long *arr, int s)
{
    if(s>1)
    {
        int n=s/2;
        int m=s-n;
        long long x = getSum(arr,n);
        long long y = getSum(arr+n,m);
        long long z = inmerge(arr,n,m);
        return x + y + z;
    }
    else{
      return 0;
    }
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--){
        ans = 0;
		int n;
        cin>>n;
        long long nums[n];
        
        for(int i=0;i<n;i++){
            cin>>nums[i];
        }
        ans = getSum(nums,n);
        cout<<ans<<endl;
    }
    return 0;
}