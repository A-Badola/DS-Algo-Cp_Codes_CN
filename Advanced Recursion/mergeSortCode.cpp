/*
Sort an array A using Merge Sort.
Change in the input array itself. So no need to return or print anything.
Input format :
First line of input will contain T number of test cases
First line of every input will contain a single integer N size of the input array.
second line of each input will contain N space-separated integers.
Output format :
For every test case print, array elements in increasing order (separated by space) in a separate line.
Constraints :
1 <= T <= 10
1 <= n <= 10^5
Sample Input 1 :
1
6 
2 6 8 5 4 3
Sample Output 1 :
2 3 4 5 6 8
Sample Input 2 :
1
5
2 1 5 2 3
Sample Output 2 :
1 2 2 3 5 
*/

#include<bits/stdc++.h>
using namespace std;

void inmerge(int *a,int n,int m){
    int i=0,j=0,k=0;
    int* temp = new int[n+m];
    while(j<n && k<m){
        temp[i++] = a[j]<a[n+k]?a[j++]:a[n+k++];
    }
    
    while(j<n){
        temp[i++] = a[j++];
    }
    while(k<m){
        temp[i++]= a[n+k++];
    }
    
    for(int i=0;i<n+m;i++){
        a[i]=temp[i];
    }
}


void mergeSort(int * a, int s){
    if(s>1){
        int n = s/2;
        int m = s-n;
        mergeSort(a,n);
        mergeSort(a+n,m);
        inmerge(a,n,m);
    }
}
int main(){
    
    int t;
    cin>>t;
    while(t--){
        int s;
        cin>>s;
        int ar[s];
        for(int i=0;i<s;i++){
            cin>>ar[i];
        }
        mergeSort(ar,s);
        for(int i=0;i<s;i++){
            cout<<ar[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}