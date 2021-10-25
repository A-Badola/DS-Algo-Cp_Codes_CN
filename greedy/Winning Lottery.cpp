/*
Harshit knows through his resources that this time the winning lottery number is the smallest number whose sum of the digits is S and the number of digits is D. You have to help Harshit and print the winning lottery number.
Input Format:
First line of input contians an integer T, representing the number of test cases.
Next T lines contains two space-separated integers: S,D
Constraints:
1 <= T <= 1000
1 <= D <= 1000
1 <= S <= 9*D
Time Limit: 1 second
Output Format
The output contains a single integer denoting the winning lottery number
Sample Input 1:
1
9 2
Sample Output 1:
18
Explanation
There are many other possible numbers like 45, 54, 90, etc with the sum of digits as 9 and number of digits as 2. The smallest of them is 18.
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    
   	int t;
    cin>>t;
    while(t--){
		int s,d;
        cin>>s>>d;
        int k = 9;
        vector<int> ans;
        while(s>1 && d>1){
            int val = s;
            if(s>k){
                int hm = ceil(double(s)/double(k))-1;
                for(int i=0;i<hm;i++){
                    ans.push_back(k);
                    d--;
                }
                s = s - hm*k;
                k = k-1;
            }
            else{
                k = k-1;
            }
        }
        
        int sz = ans.size();
        //for(int i=sz-1;i>=0;i--){
         //  cout<<ans[i];
        //}
        //cout<<endl;
        while(d>1){
        	ans.push_back(0);
            sz++;
            d--;
        }
        ans.push_back(s);
		sz++;
        for(int i=sz-1;i>=0;i--){
            cout<<ans[i];
        }
        cout<<endl;  
    }
    return 0;
}