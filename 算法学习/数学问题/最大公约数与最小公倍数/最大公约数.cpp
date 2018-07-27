#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b){
  if(b==0){return a;}
  else{
    return gcd(b,a%b);
  }
}
int main(int argc, char const *argv[]) {
  printf("%d\n",gcd(24,36));
  return 0;
}
