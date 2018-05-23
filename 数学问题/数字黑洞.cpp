#include<bits/stdc++.h>
using namespace std;
int sum(int a[]){
  int i=0;
  int output=0;
  for(i=0;i<4;i++){
    output*=10;
    output+=a[i];
  }
  return output;
}
void Break(int a[],int b){
  int i=0;
  for(i=0;i<4;i++){
    a[i]=b%10;
    b/=10;
  }
}
bool check(int a[]){
  int i=0;
  int p=a[0];
  for(i=1;i<4;i++){
    if(a[i]!=p){
      return false;
    }
  }
  return true;
}
bool cmp_large_to_small(int p,int q){
  return p-q>0?true:false;
}
int main(int argc, char const *argv[]) {
  int i=0,input,Input[4];
  scanf("%d",&input);
  Break(Input,input);
  int large,small;
  do{
    sort(Input,Input+4,cmp_large_to_small);
    large=sum(Input);
    printf("%04d",large);

    printf(" - ");

    sort(Input,Input+4);
    small=sum(Input);
    printf("%04d",small);

    input=large-small;
    printf(" = %04d\n",input);

    Break(Input,input);
  }while(input!=6174&&input!=0);
  return 0;
}
