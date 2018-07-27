#include<bits/stdc++.h>
using namespace std;
#define N 1000
int length=0;
bool is_prime(int max){
  int i,j=0;
  if(max<=1){
    return false;
  }
  else{
    for(i=2;i*i<=max;i++){
      if(max%i==0){
        return false;
      }
    }
    return true;
  }
}
struct prime{
    int p;
    int count;
}x[N];

void block_into_prime(int max){
  int i,j=0;
   for(i=2;i<=max;i++){    // 可能出现比sqrt(max)更大的素因子
     x[i].count=0;
     if(is_prime(i)){
       x[j++].p=i;
     }
   }
   length=j;
   for(j=0;j<length;j++){
       while(max%(x[j].p)==0){
          x[j].count++;
          max/=x[j].p;
       }
       if(max==1){
         break;
       }
   }
}
int main(){
  int i=0,input=1270;
  for(i=0;i<N;i++){
    x[i].count=0;
  }
  block_into_prime(input);
  //cout<<"length:  "<<length<<endl;
  for(i=0;i<length;i++){
      if(x[i].count>0){
            cout<<x[i].p<<":   "<<x[i].count<<endl;
      }
  }
}
