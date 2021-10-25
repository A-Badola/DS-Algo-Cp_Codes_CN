/*
RQ2
Given a sequence A1 , A2 , A3 .. AN of length N. Find total number of wave subsequences having length greater than 1.
Wave subsequence of sequence A1 , A2 , A3 .. AN is defined as a set of integers i1 , i2 .. ik such that Ai1 < Ai2 > Ai3 < Ai4 .... or Ai1 > Ai2 < Ai3 > Ai4 .... and i1 < i2 < ...< ik.Two subsequences i1 , i2 .. ik and j1 , j2 .. jm are considered different if k != m or there exists some index l such that il ! = jl
Input Format:
First line of input consists of integer N denoting total length of sequence.Next line consists of N integers A1 , A2 , A3 .. AN .
Constraints:
1 ≤ N ≤ 10^5
1 ≤ Ai ≤ 10^5
Output Format:
Output total number of wave subsequences of given sequence. Since answer can be large, output its modulo with 10^9+7
Sample Input 1:
5
1 3 5 4 2
Sample Output 1:
17
Explanation:
All the possible sequences are: [ 1 3 ] , [1 5 ] , [ 1 4 ] , [1 2 ] , [1 3 2] , [1 4 2 ] , [1 5 2] , [1 5 4] , [3 5] , [3 4] , [3 2] , [3 5 2] , [3 4 2] , [3 5 4] , [5 4] , [5 2 ] , [4 2] . Note that value in the bracket are the values from the original sequence whose positions are maintained.
*/

#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define MAX 100001

int maxim;
int N;
vector<int> BIT0(MAX), BIT1(MAX);
int arr[MAX];
int dp[MAX][2];

void update(int x, int val, vector<int> &bits) {
    for(; x <= maxim; x += x & -x)
        bits[x] = (bits[x] + val) % MOD;
}

int query(int x, vector<int> &bits) {
    int sum = 0;
    for(; x > 0; x -= x & -x)
        sum = (sum + bits[x]) % MOD;
    return sum;
}

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        maxim = max(maxim, arr[i]);
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        /*
        for(int i=1;i<=maxim+1;i++){
          cout<<BIT0[i]<<" ";
        }
        cout<<endl;
        for(int i=1;i<=maxim+1;i++){
          cout<<BIT1[i]<<" ";
        }
        cout<<endl;
        */
        update(arr[i], 1, BIT1);
        update(arr[i], 1, BIT0);

        dp[i][0] = (query(maxim, BIT1) - query(arr[i], BIT1)) % MOD;
        dp[i][1] = query(arr[i] - 1, BIT0) % MOD;

        update(arr[i], dp[i][0], BIT0);
        update(arr[i], dp[i][1], BIT1);
		/*
        for(int i=1;i<=maxim+1;i++){
          cout<<BIT0[i]<<" ";
        }
        cout<<endl;
        for(int i=1;i<=maxim+1;i++){
          cout<<BIT1[i]<<" ";
        }
        cout<<endl;
        */
        dp[i][0] = (dp[i][0] + MOD) % MOD;
        dp[i][1] = (dp[i][1] + MOD) % MOD;

        ans = (ans + dp[i][0]) % MOD;
        ans = (ans + dp[i][1]) % MOD;
    }

    ans = (ans + MOD) % MOD;
    cout << ans << "\n";

    return 0;
}