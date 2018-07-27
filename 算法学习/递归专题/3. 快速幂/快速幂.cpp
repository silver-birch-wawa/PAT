#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL bPow(LL a,LL b,LL m){
  if(b==0){
    return 1;
  }
  if(b&1){
    return a*bPow(a,b-1,m)%m;
  }
  else{
    LL mul=bPow(a,b/2,m);
    return mul*mul%m;
  }
}
int main() {
  LL a=8237,b=233,m=1011;
  LL x=bPow(a,b,m);
  cout<<x;
  return 0;
}
