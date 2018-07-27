#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
  if(b==0){return a;}
  else{
    return gcd(b,a%b);
  }
}
int lcm(int a,int b){
  return a/gcd(a,b)*b;   // a*b可能溢出，所以需要先除个gcd(a,b)
}
int main(int argc, char const *argv[]) {
  cout<<lcm(24,16);
  return 0;
}
