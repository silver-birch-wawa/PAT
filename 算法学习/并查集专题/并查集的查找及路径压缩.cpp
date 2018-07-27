#include <bits/stdc++.h>
using namespace std;
#define N 100;
int father[N];

// 查找父节点
int findFather(int x){
  while(x!=father[x]){
    x=father[x];
  }
  return x;
}
// 合并操作(用于添加新的元素)
void Union(int a,int b){
  int faA=findFather(a);
  int faB=findFather(b);
  if(faA!=faB){
    father[faA]=faB;   // 合并了
  }
}

// 路径压缩--->找到爸爸后顺便把孙子全部优化。
int optimize_findFather(int x){
  int a=x;
  int z;
  while(x!=father[x]){
    x=father[x];
  }
  while(a!=father[a]){
    z=a;
    a=father[a];
    father[z]=x;
  }
  return x;
}
int main(){
  int i;
  for(i=0;i<N;i++){
    father[i]=i;  // 初始化所有节点
  }

  // 查找是否在一个集合内
  findFather(2)==findFather(4);
}
