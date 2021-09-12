/*
Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.
Note : The order of strings are not important. Just print different strings in new lines.
Input Format :
Integer n
Output Format :
All possible strings in different lines
Constraints :
1 <= n <= 10^6
Sample Input:
23
Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf
*/

#include <iostream>
#include <string>
using namespace std;

string keypad[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void pKN(int num,string s){
    if(num==0||num==1){
        cout<<s<<endl;
        return;
    }
    int smalln = num/10;
    int remn = num%10;
    for(int i=0;i<keypad[remn].size();i++){
        pKN(smalln,keypad[remn][i]+s);
    }
}

void printKeypad(int num){
    string s;
    s="";
    pKN(num,s);
}
