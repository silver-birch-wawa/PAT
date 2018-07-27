#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<math.h>
using namespace std;

struct Input{
  char input[20];
}input[20];

bool cmp(struct Input a,struct Input b){
  int A=atoi(a.input);
  int B=atoi(b.input);

  int p1=A*pow(10,strlen(b.input))+B;
  int p2=B*pow(10,strlen(a.input))+A;
  if(p1>=p2){
    return true;
  }
  else{
    return false;
  }
}
int main(){
  //int input;
  int i,j,k,length,compare;
  int count=0;

  scanf("%d",&count);
  for(i=0;i<count;i++){
    scanf("%s",input[i].input);
  }
  length=i;

  sort(input,input+length,cmp);

  //printf("\n");
  for(i=0;i<length;i++){
    printf("%s",input[i].input);
  }
}
