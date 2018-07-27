#include<bits/stdc++.h>
using namespace std;
// n!可以分离出n/p+n/p^2+n/p^3+.....个p因子
long long calc(long long n,int p){
  long long ans=0;
  while(n){
    ans+=n/p;
    n/=p;
  }
  return ans;
}
int main(){
  long long n=10;
  long long ans=calc(n,2);
  printf("%ld\n",ans);
}
