#include<bits/stdc++.h>
using namespace std;
#define N 100000
#define lowbit(i) ((i)&(-i))
// 最大值
int maxnum=N;
// A表示该数出现的次数
int A[N]={0};
// C表示小于等于它的lowbit个数的和
int C[N]={0};

int K=0;
// 第K大的值

vector<int>v;
// 更新节点时对相关节点的操作
void update(int num,int v){
  int i,j;
  int length=num;
  while(length<=maxnum){
    C[length]+=v;
    length+=lowbit(length);
  }
}
// 对A和C数组的操作
void add(int num){
  A[num]++;
  update(num,1);
}
void del(int num){
  A[num]--;
  update(num,-1);
}
// 计算小于等于num的数组元素的和
int sumup(int num){
  int length=num;
  int sum=A[num];
  length--;
  while(length>0){
    sum+=C[length];
    length-=lowbit(length);
  }
  return sum;
}
// 计算区间内的和
int sumBetween(int start,int end){
  return sumup(end)-sumup(start-1);
}
void findMedian(){
  if(v.empty()){
    printf("Invalid\n");
    return;
  }
  // 获取目标K
  if(v.size()&1){
    K=(v.size()+1)/2;
  }
  else{
    K=v.size()/2;
  }
  // 不需要像分块那样一个一个试过去，因为树状数组的sumup肯定是上升的，
  // 只需要二分查找即可。如果分块法采用二分查找，因为需要遍历的元素较多，不划算。
  int l=1;
  int r=maxnum;
  while(l<r){
    // 当l==r时停止，二分查找到了最终解
    int mid=(l+r)/2;
    if(sumup(mid)>=K){
      r=mid;
    }
    else{
      l=mid+1;
    }
  }
  printf("%d\n",l);
  // 理论上返回l还是r都是一样的
}
void Pop(){
  if(v.empty()){
    printf("Invalid\n");
    return;
  }
  int num=v[v.size()-1];
  del(num);
  printf("%d\n",num);
  v.pop_back();
}
void Push(int num){
  v.push_back(num);
  add(num);
}
int main(){
  char cmd[100];
  int i,j,times=0;
  scanf("%d",&times);
  for(i=0;i<times;i++){
    scanf("%s",cmd);
    if(strcmp(cmd,"Pop")==0){
      Pop();
    }
    else if(strcmp(cmd,"PeekMedian")==0){
      findMedian();
    }
    else{
      int num;
      scanf("%d",&num);
      Push(num);
    }
  }
}
/*
4
Push 3
Push 13
Push 3
Push 31
*/
