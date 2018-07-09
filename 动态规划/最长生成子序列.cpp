#include <bits/stdc++.h>
using namespace std;
#define N 10000
int points,edges;
int MAX[N]={0};
int num[N]={0};
int main(){
  int i=0,j,input,length=0;
  scanf("%d",&length);
  for(i=0;i<length;i++){
    scanf("%d",&input);
    num[i]=input;
  }
  length=i;
  // 从MAX[1]开始，所以MAX[0]需要初始化
  MAX[0]=num[0];
  for(i=1;i<length;i++){
    // 默认i是最大连续子串的终点end，也就是说num[i]必须在最大连续子串中
    // 只有两种可能，
    // 1. num[i]一个结果
    // 2. num[i]+MAX[i-1]  因为MAX[i-1]中包含num[i-1]，所以肯定连续。
    if(num[i]>num[i]+MAX[i-1]){
      MAX[i]=num[i];
    }
    else{
      MAX[i]=num[i]+MAX[i-1];
    }
  }
  int max_sum=0;
  int end_point=0;
  // 从MAX[0]->MAX[length]中选择最大值，因为最大子串的end不一定在最后。
  for(i=0;i<length;i++)
  {
    if(max_sum<MAX[i]){
      max_sum=MAX[i];
      end_point=i;
    }
  }
  cout<<"max:"<<max_sum<<endl;
  cout<<"end_point:"<<end_point+1<<endl;
}


/*
1 8 -2 10 8 -4 7 5 -29 10
33
*/
