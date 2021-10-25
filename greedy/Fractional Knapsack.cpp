/*
You are given weights and values of N items. You have to select and put these selected items in a knapsack of capacity W. Select the items in such a way that selected items give the maximum total value possible with given capacity of the knapsack.
Note: You are allowed to break the items in parts.
Input Format:
The first line of input contains two space separated integers, that denote the value of N and W.
Each of the following N lines contains two space separated integers, that denote value and weight, respectively, of the N items.    
Constraints:
1 <= N = 2*10^5
1 <= W <= 10^9
1 <= value, weight <= 10^5
Time Limit: 1 sec
Output Format:
Print the maximum total value upto six decimal places.
Sample Input 1:
4 22
6 4
6 4
4 4
4 4
Sample Output 1:
20.000000
Explanation:
The total weight of all the items is 16 units, which is less than the total capacity of knapsack, i.e 22 units. Hence, we will add all the items in the knapsack and total value will be 20 units.
*/

#include<bits/stdc++.h>
using namespace std;

bool compare(pair<double,double> a, pair<double,double> b){
	return (a.first/a.second) > (b.first/b.second);
}

int main(){    
    int N,W;
    cin>>N>>W;
    vector<pair<double,double>> v;
    double val,w;
    for(int i=0;i<N;i++){
		cin>>val>>w;
        v.push_back(make_pair(val,w));
    }
    sort(v.begin(),v.end(),compare);
    double answer = 0;
    int wleft = W;
    for(int i=0;i<N;i++){
		if(v[i].second <= wleft){
            wleft = wleft - v[i].second;
            answer = answer + v[i].first; 
        }
        else{    
            answer = answer + (double(v[i].first)/v[i].second)*(wleft);
            wleft = 0;
        }
    }
    cout<<fixed<<setprecision(6)<<answer;
    return 0;
}