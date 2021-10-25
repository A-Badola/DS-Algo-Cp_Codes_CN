/*
A cube free number is a number who’s none of the divisor is a cube number (A cube number is a cube of a integer like 8 (2 * 2 * 2) , 27 (3 * 3 * 3) ). So cube free numbers are 1, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12, 13, 14, 15, 17, 18 etc (we will consider 1 as cube free). 8, 16, 24, 27, 32 etc are not cube free number. So the position of 1 among the cube free numbers is 1, position of 2 is 2, 3 is 3 and position of 10 is 9. Given a positive number you have to say if its a cube free number and if yes then tell its position among cube free numbers.
Note: we will consider 1 as the 1st cube free number
Input Format:
First line of the test case will be the number of test case T 
Each test case contain an integer N
Output Format:
For each test case print the position of N in cube free numbers and if its not a cube free number print "Not Cube Free" in a newline.
Constraints:
1 <= T <= 10^5
1 <= N <= 10^6
Sample Input:
10
1
2
3
4
5
6
7
8
9
10
Sample Output:
1
2
3
4
5
6
7
Not Cube Free
8
9
*/

#include<bits/stdc++.h>
using namespace std;

#define MAX 1000001
long long cf[MAX];

void cubeFree(){
    for(int i=0;i<MAX;i++){
      cf[i] = 1;
    }
    cf[0]= 0;
    for(int i=2;i<=100;i++){
        if(cf[i]!=0){
          int num = i*i*i;
          int k = 1;
          while(num*k < MAX){
            cf[num*k] = 0;
            k++;
          }
        }
    }
    
    for(int i=2;i<MAX;i++){
		  cf[i] = cf[i] + cf[i-1];
      //cout<<cf[i]<<" ";
    }
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int t;
    cin>>t;
    cubeFree();
    while(t--){
        int n;
        cin>>n;
        //for(int i=0;i<=n;i++){
         // cout<<cf[i]<<" ";
        //}        
        //cout<<endl;
        if(cf[n]!=cf[n-1]){
            cout<<cf[n]<<endl;
        }
        else
        {
            cout<<"Not Cube Free"<<endl;
        }
    }
    return 0;
}