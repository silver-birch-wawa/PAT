#include<bits/stdc++.h>
using namespace std;
struct bign{
  int d[1000];
  int length;
  bool signal;
  bign(){
    signal=true;
    memset(d,0,sizeof(d));   // 除了设置为0外没有别的用处
    length=8;
  };
};
int main(){
    bign b;
    cout<<b.length<<endl;
    cout<<b.d[0]<<endl;
}
