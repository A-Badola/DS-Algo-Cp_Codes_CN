/*
Given n, calculate and print the sum :
LCM(1,n) + LCM(2,n) + .. + LCM(n,n)
where LCM(i,n) denotes the Least Common Multiple of the integers i and n.
Input Format :
First line of input will contain T(number of test case), each test case follows as.
An Integer N
Output Format :
Required sum for each test case in newline.
Constraints :
1 <= T <= 10^4
1 <= n <= 10^5
Sample Input 1 :
1
5
Sample Output 1 :
55
Sample Input 2 :
1
2
Sample Output 2 :
4
*/

#include<bits/stdc++.h>
using namespace std;
#define MAX 100005

long long phi[MAX];
long long ans[MAX];

void getPhi(){
    for(int i=0;i<=MAX;i++){
        phi[i] = i;
    }
    //for(int i=0;i<10;i++){
//		cout<<phi[i]<<" ";
  //  }
    //cout<<endl;
    
    for(int i=2;i<=MAX;i++){
		if(phi[i]==i){
            for(int j=i;j<=MAX;j+=i){
                phi[j] = phi[j] - phi[j]/i;
            }
        }
    }
    
    //for(int i=0;i<10;i++){
      //  cout<<phi[i]<<" ";
    //}
    //cout<<endl;
}

void lcmSum(){
    for(int i=1;i<MAX;i++){
        // for all j which have i as divisor
        for(int j=i;j<MAX;j+=i){
            ans[j] = ans[j] + i*phi[i];
        }
    }
    for(int i=1;i<MAX;i++){
        long long answer = ans[i];
        answer = (answer+1);
        answer = (i*(answer))/2;
        ans[i] =  answer;
    }
}


int main(){
    
    // write your code here
	int t;
    cin>>t;
    getPhi();
    memset(ans,0,sizeo f(ans));
    lcmSum();
    while(t--){
		int n;
        cin>>n;
        cout<<ans[n]<<endl;
    }
    return 0;
}