#include<bits/stdc++.h>
using namespace std;
#define N 1000
// 单个数组成员的大小
int A[N]={0};
// 前面i位的数组值之和
int C[N]={0};
// 输入次数
int times=0;

// 计算减去low位bit1后的值
int lowbit(int num){
  // 不能处理0的情况,直接返回减去二进制最右边的1之后的值
  return num-(num&(-num));
}
// 计算C[i]的值
int countC(int c){
  int i,j;
  // 在c的时候C[c]+=A[c]
  C[c]+=A[c];
  int length=c;
  length=length-1;
  // 在小于c的时候,C[c]+=C[length],减少计算量.
  while(length>lowbit(c)){
    C[c]+=C[length];
    length=lowbit(length);
    // C[c]是由一系列 C[length-lowbit(length)]组成的(length从c-1开始起步)
  }
}
// 获取num及之前的A[i]之和
int getSum(int num){
  if(sum==0){
    return 0;
  }
  int length=num;
  int sum=0;
  while(length>0){
    sum+=C[length];
    length=lowbit(length);
  }
  return sum;
}
// 获取区间内元素之和
int sumBetween(int start,int end){
  return getSum(end)-getSum(start-1);
}
// 对A[num]+v后对相关C[i]的修改
void update(int num,int v){
  int i,j;
  // i 叠加 lowbit(i),修改 i 对应的 C[i]
  for(i=num;i<=times;i+=((-i)&i)){
    C[i]+=v;
  }
}

int main(){
  scanf("%d",&times);
  int i,input;
  for(i=1;i<times+1;i++){
    scanf("%d",&input);
    A[i]=input;
    countC(i);
  }
  // 更新A,C数组
  update(9,10);
  // 打印 C数组成员
  for(i=1;i<times+1;i++)
  {
    cout<<"c["<<i<<"]:"<<C[i]<<endl;
  }
  cout<<"sum of [12,16]:"<<sumBetween(12,16)<<endl;
}

/*
16
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
*/
