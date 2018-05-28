#include<bits/stdc++.h>
using namespace std;
class bign{
  public:
    int d[1000];
    int length;
    bign(){
      length=0;
      memset(d,0,sizeof(d));
    }
    // 读取输入的时候要倒序，这样d[0]才是最小值
    void init(){
      int i=0;
      char a[1000];
      scanf("%s",a);
      for(i=0;i<strlen(a);i++){
        d[strlen(a)-i-1]=a[i]-'0';
      }
      length=i;
    }
    // 打印从高位往低位打印。
    void print(){
      int i=0;
      for(i=0;i<length;i++){
        printf("%d",d[length-1-i]);
      }
    }
    // 加法运算
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
    // 
};
int main(int argc, char const *argv[]) {
  bign b1,b2;
  b1.init();
  b2.init();

  bign c=b1.add(b2);

  c.print();

  return 0;
}
