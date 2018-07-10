#include <bits/stdc++.h>
using namespace std;
#define N 10000
int points,edges;
int MAX[N]={0};
// 以该节点为端点的不下降子序列的最大长度
int num[N]={0};
// 存放输入
int son[N]={0};
// 存放上一级节点
int findstart(int end,int maxlength){
  int i,j;
  int start=end;
  cout<<num[end]<<">>";
  while(start>=0){
    // 当start==son[start]，说明到达了子串的起点，break
    if(start!=son[start]){
      start=son[start];
      cout<<num[start]<<">>";
    }
    else{
      break;
    }
  }
  cout<<endl;
  return start;
}
int main(){
  int i=0,j,input,length=0;
  scanf("%d",&length);
  for(i=0;i<length;i++){
    scanf("%d",&input);
    num[i]=input;
    MAX[i]=1;
    son[i]=i;
  }
  length=i;

  MAX[0]=1;
  // 以i为子序列的终点，遍历所有num比它小的MAX
  // 得到max(MAX[i],MAX[j]+1)作为MAX[i]的最终值
  for(i=1;i<length;i++) {
    for(j=0;j<i;j++){
      if(num[j]<num[i]){
        if(MAX[i]<MAX[j]+1){
          // j更适合加入串
          MAX[i]=MAX[j]+1;
          // 记录串中上一个节点的坐标
          son[i]=j;
        }
      }
    }
  }

  // 从MAX[i]中找出最长子串的长度
  int maxlength=0;
  int end=-1;
  int start=0;
  for(i=0;i<length;i++){
    if(MAX[i]>maxlength){
      maxlength=MAX[i];
      end=i;
    }
  }

  cout<<"maxlength:"<<maxlength<<endl;
  cout<<"end:"<<end+1<<endl;
  // 利用end和maxlength沿着son[]一路补全整个串
  start=findstart(end,maxlength);
  cout<<"start:"<<start+1<<endl;
}


/*
10
1 3 5 4 2 3 6 4 2 7
*/
