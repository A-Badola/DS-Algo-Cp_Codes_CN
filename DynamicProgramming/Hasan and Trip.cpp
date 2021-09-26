//R
/*
Hasan has finally finished his final exams and he decided to go in a trip among cities in Syria.
There are N cities in Syria and they are numbered from 1 to N, each city has coordinates on plane, i-th city is in (Xi, Yi).
Hasan is in first city and he wants to visit some cities by his car in the trip but the final destination should be N-th city and the sequence of cities he will visit should be increasing in index (i.e. if he is in city i he can move to city j if and only if i < j ).
Visiting i-th city will increase Hasan's happiness by Fi units (including first and last cities), also Hasan doesn't like traveling too much, so his happiness will decrease by total distance traveled by him.
Help Hasan by choosing a sequence of cities to visit which maximizes his happiness.
Input format:
First line will contain T(number of test case).
First line of each test case will contain an integer N 
Next N lines of that test case will contain three space-separated integers Xi, Yi, Fi (coordinates and happiness)
Output format:
For each test Output one number rounded to 6 digits after floating point, the maximum possible happiness in newline, Hasan can get. 
Note: If answer is 2 print 2.000000
Constraints:
1 <= T <= 50
1 <= N <= 500
0 <= Xi, Yi, Fi <= 100,000
Sample Input
1
3
0 0 1
3 1 1
6 0 9
Sample Output
4.675445
*/

#include<bits/stdc++.h>
using namespace std;

double mat[505][505];
double dist(double* x,double* y,int j,int i){
  return sqrt((x[i]-x[j])*(x[i]-x[j]) + ((y[i]-y[j])*(y[i]-y[j])));
}

double maxHap(double* x,double* y,double* f,int n,int sz,int i){
  if(n==1){
    return mat[n][i] = f[0] - dist(x,y,n-1,i);
  }
  if(n==sz){
    return mat[n][i] = f[sz-1] + maxHap(x,y,f,n-1,n,n-1);
  }
  if(mat[n][i]!=0.0){
      return mat[n][i];
  }
  return mat[n][i] = max(f[n-1] - dist(x,y,n-1,i) + maxHap(x,y,f,n-1,sz,n-1),maxHap(x,y,f,n-1,sz,i));
}

int main(){
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  int t;
  cin>>t;
  while(t--){
    memset(mat,0.0,sizeof(mat));
    int n;
    cin>>n;
    double* x = new double[n];
    double* y = new double[n];
    double* f = new double[n];

    for(int i=0;i<n;i++){
      cin>>x[i]>>y[i]>>f[i];
    }
	
    cout<<fixed<<setprecision(6)<<maxHap(x,y,f,n,n,n-1)<<endl;
    delete[] x;
    delete[] y;
    delete[] f;
  }
  return 0;
}