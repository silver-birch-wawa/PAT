#include<bits/stdc++.h>
using namespace std;
#define N 1001
bool p[N]={false};
// 10^5以内可以接受。算法复杂度 nlog(n)
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
void find_prime(int max){
  int i=0;
  for(i=2;i<=max;i++){
    if(is_prime(i)){
        p[i]=true;
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
