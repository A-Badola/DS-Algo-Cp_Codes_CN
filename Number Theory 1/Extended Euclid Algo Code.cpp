#include<bits/stdc++.h>
using namespace std;

class triplet{
  public:
    int x;
    int y;
    int gcd;
};

triplet extendedEuclid(int a, int b){
  //base case
  if(b==0){
    triplet ans;
    ans.x = 1;
    ans.y = 0;
    ans.gcd = a;
    return ans;
  }

  //extendedEuclid Algo
  triplet smallAns = extendedEuclid(b,a%b);
  triplet ans;
  ans.gcd = smallAns.gcd;
  ans.x = smallAns.y;
  ans.y = smallAns.x - (a/b)*smallAns.y;
  return ans;
}

int main(){
  //freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);

  int a = 15;
  int b = 10;
  triplet ans = extendedEuclid(a,b);
  cout<<ans.x<<" "<<ans.y<<endl;
  return 0;
}