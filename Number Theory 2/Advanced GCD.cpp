#include<bits/stdc++.h>
using namespace std;

void swap(int& a, int& b){
	int temp = a;
    a = b;
    b = temp;
}

long long gcd(int a, int b){

    if(b==0){
		return a;
    }
    return gcd(b, a%b);
}

long long getMod(string s, int b){
    //cout<<s<<endl;
    int n = s.size();
    long long ans = 0;
    int temp;
    for(int i=0;i<n;i++){
    	temp = s[i] - '0';
        //cout<<temp;
        ans = (((ans)*(10%b))%b + temp%b)%b; 
    }
    //cout<<endl;
    return ans;
}

int main(){
    
    // write your code here
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--){
        long long b;
        cin>>b; 
        
        string s;
        cin>>s;
       // cout<<s<<endl;
 		
       // cout<<b<<endl;
        long long first_Mod = getMod(s,b);
        cout<<gcd(b,first_Mod)<<endl;
    }
    return 0;
}