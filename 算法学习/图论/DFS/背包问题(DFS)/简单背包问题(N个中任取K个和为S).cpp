#include <bits/stdc++.h>
using namespace std;
//不知道为啥超时30%....
int v[100]={0};   // 存放输入
int circle=0;     // 记录循环所需次数
int sum;     // 存放目标值
bool sign=false;    // 做递归使的信号

void DFS(int index,int weight){
  int w=weight+v[index];
  //cout<<"weight:"<<weight<<endl;
  // 越界则失败
  if(index==circle){
    return;
  }
  else{
    // 溢出回退
    if(w>sum){
      DFS(index+1,weight);
    }
    // 好运爆表
    else if(w==sum){
      sign=true;
      return;
    }
    // 正常分叉
    else{
      DFS(index+1,weight);
      DFS(index+1,w);
    }
  }
}
int main(){
  int i,input;
  scanf("%d %d",&sum,&circle);
  for(i=0;i<circle;i++){
    scanf("%d",&input);
    v[i]=input;
  }
  DFS(0,0);
  if(sign){
    printf("YES");
  }
  else{
    printf("NO");
  }
}
