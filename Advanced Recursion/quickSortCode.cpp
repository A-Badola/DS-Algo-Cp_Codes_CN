/*
Sort an array A using Quick Sort.
Change in the input array itself. So no need to return or print anything.


Input format :
First line will contain T number of test case and each tet case will consist of two lines.
Line 1 : Integer n i.e. Array size
Line 2 : Array elements (separated by space)
Output format :
for every test case print rray elements in increasing order (separated by space) in a new line.
Constraints :
1 <= T <= 10
1 <= n <= 10^5
0 <= arr[i] <= 10^9
Sample Input 1 :
1
6 
2 6 8 5 4 3
Sample Output 1 :
2 3 4 5 6 8
Sample Input 2 :
1
5
1 5 2 7 3
Sample Output 2 :
1 2 3 5 7 
*/

#include<bits/stdc++.h>
using namespace std;

int inPartition(int* a,int l,int h){
    int i=l+1;
    int j;
    int p;
    p = a[l];
    for(j=l+1;j<h;j++){
        if(a[j]<=p){
            int temp = a[j];
            a[j]=a[i];
            a[i]=temp;
            i++;
        }
    }
    int temp = a[i-1];
    a[i-1]=a[l];
    a[l]=temp;
    return (i-1);
}

void qsort(int* a,int l,int h){
    int p;
    if(h-l>0){
        p = inPartition(a,l,h);
        qsort(a,l,p);
        qsort(a,p+1,h);
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
		int n;
        cin>>n;
        int ar[n];
        for(int i=0;i<n;i++){
            cin>>ar[i];
        }
        qsort(ar,0,n);
        for(int i=0;i<n;i++){
            cout<<ar[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}