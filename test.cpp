#include <bits/stdc++.h>
using namespace std;
#define N 10000
int points,edges;
int MAX[N]={0};
int num[N]={0};
int main(){
  int i=0,j,input,length=0;
  //scanf("%d",&length);
  //for(i=0;i<length;i++){
  while(1){
    scanf("%d",&input);
    num[i++]=input;
    char c=getchar();
    if(c=='\n')break;
  }
  //}
  length=i;
  MAX[0]=num[0];
  for(i=1;i<length;i++){
    if(num[i]>num[i]+MAX[i-1]){
      //MAX[i]=MAX[i];
      MAX[i]=num[i];
    }
    else{
      MAX[i]=num[i]+MAX[i-1];
    }
  }
  int max_sum=0;
  int end_point=0;
  for(i=0;i<length;i++)
  {
    if(max_sum<MAX[i]){
      max_sum=MAX[i];
      end_point=i;
    }
    //cout<<MAX[i]<<endl;
  }
  cout<<max_sum;
  //cout<<"max:"<<max_sum<<endl;
  //cout<<"end_point:"<<end_point+1<<endl;
}
