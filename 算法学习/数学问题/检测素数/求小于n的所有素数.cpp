#include<bits/stdc++.h>
using namespace std;
#define N 1001
bool p[N]={0};
// 注意，如果是a[100]={0}是所有的值为0,而a[100]={1}则是只有第一个值为1；
// 为了初始化方便，false为素数，true为非素数
int pNum=0;
bool is_prime(int a){
   if(a==1){
     return false;
   }
   //long long sqr=(long long)sqrt(1.0*a);
   for(int i=2;i*i<=a;i++){
     if(a%i==0){
       return false;
     }
   }
   return true;
}
// 利用小于它的素数计算是否成立，用于求解小于n的所有素数
void find_prime(int max){
  int i=0,j=0;
  p[0]=p[1]=true;
  for(i=2;i<=max;i++){
    if(p[i]==false){
      if(is_prime(i)){
          //p[i]=true;
          for(j=i+i;j<=max;j+=j){
              p[j]=true;
          }
      }
      else{
        p[i]=true;
      }
    }
  }
}
int main(){
  int a=13,i;
  find_prime(a);
  for(i=0;i<a+1;i++){
    printf("%d: %d\n",i,p[i]);
  }
}
