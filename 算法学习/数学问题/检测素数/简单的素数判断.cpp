#include<bits/stdc++.h>
using namespace std;
bool is_prime(long long a){
   if(a<=1){
     return false;
   }
   //long long sqr=(long long)sqrt(1.0*a);
   for(long long i=2;i*i<=a;i++){
     if(a%i==0){
       return false;
     }
   }
   return true;
}
int main(){
  long long a=4;
  if(is_prime(a)){
    cout<<"true"<<endl;
  }
  else{
    cout<<"false"<<endl;
  }
}
