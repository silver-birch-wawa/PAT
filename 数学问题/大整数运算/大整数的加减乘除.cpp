#include<bits/stdc++.h>
using namespace std;
class bign{
  public:
    int d[1000];  // 存储数据
    int length;   // 记录长度
    bool signal;  // 正负号标记 true+ false-
    bign(){
      length=0;
      signal=true;
      memset(d,0,sizeof(d));
    }
    // 读取输入的时候要倒序，这样d[0]才是最小值
    void init(){
      int i=0;
      char a[1000];
      scanf("%s",a);
      if(a[0]=='-'){
        signal=false;
      }
      i=1;
      for(i;i<strlen(a);i++){
        d[strlen(a)-i-1]=a[i]-'0';
      }
      length=i;
    }
    // 打印从高位往低位打印。
    void print(){
      int i=0;
      //cout<<"length:"<<length<<endl;
      if(signal==false){
        cout<<"-";
      }
      for(i=0;i<length;i++){
        printf("%d",d[length-1-i]);
      }
    }
    void exchange(bign &a){
      cout<<"exchange"<<endl;
      int i=0;
      swap(d,a.d);   // #include<algorithmn>
      swap(length,a.length);
    }
    // 加法运算,只考虑正数加正数，如果有负号则转minus。
    bign add(bign x){
      int i=0;
      bign c;
      int carry=0,temp=0;
      // c.length++解决计数的问题，carry解决进位的问题。
      for(i=0;i<max(length,x.length);i++){
            temp=d[i]+x.d[i]+carry;
            c.d[c.length++]=temp%10;
            carry=temp/10;
      }
      // 如果还有剩余，就再赋值一次。
      if(carry!=0){
        c.d[c.length++]=carry;
      }
      return c;
    }
    // 减法运算 只考虑正数减正数，如果有（+）-（-）则转plus运算，（-）-（+）则转plus然后再加个负号。
    bign minus(bign x){
      int i=0;
      bign c;
      int signal=0;

      if(x.length>length){
        exchange(x);
        c.signal=false;
      }
      if(x.length==length){
        for(i=length-1;i>=0;i--){
            if(x.d[i]==d[i]){
            }
            else if(x.d[i]>d[i]){
              signal=-1;
              break;
            }
            else{
              break;
            }
        }
      }
      if(signal==-1){
        //cout<<"oh,exchange it"<<endl;
        exchange(x);
        c.signal=false;
      }

      //x.print();

      for(i=0;i<max(length,x.length);i++){
        if(d[i]<x.d[i]){
          d[i+1]--;
          c.d[c.length++]=d[i]+10-x.d[i];
        }
        else{
          c.d[c.length++]=d[i]-x.d[i];
        }
      }
      while(c.d[c.length-1]==0&&c.length!=1){
        c.length--;
      }
      if(signal==-1){
        exchange(x);
      }
      return c;
    }
    // 乘法运算
    bign multiply(bign x){
      // 循环执行plus
    }
    bign divide(bign x){
      // 循环执行minus，溢出后回退一步。
    }
};
int main(int argc, char const *argv[]) {
  bign b1,b2;
  b1.init();
  b2.init();

  bign c=b1.minus(b2);

  c.print();

  c=b1.plus(b2);

  return 0;
}
