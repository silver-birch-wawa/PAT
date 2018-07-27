#include<bits/stdc++.h>
using namespace std;
int ex_gcd(int a,int b,int &x,int &y){
    int t;
    if(b==0){
      x=1;
      y=0;
      return a;
    }
    int gcd=ex_gcd(b,a%b,x,y);
    t=x;
    x=y;
    y=t-a/b*y;
    return gcd;
}
int main(int argc, char const *argv[]) {
  /* code */
  int x=0,y=0;
  int a=32;
  int b=27;
  int gcd=ex_gcd(a,b,x,y);
  cout<<"x:"<<x<<"y:"<<y<<endl;
  cout<<"gcd:"<<gcd<<endl;
  return 0;
}
