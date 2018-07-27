#include <bits/stdc++.h>
using namespace std;
#define N 100;
int father[N];

// ���Ҹ��ڵ�
int findFather(int x){
  while(x!=father[x]){
    x=father[x];
  }
  return x;
}
// �ϲ�����(��������µ�Ԫ��)
void Union(int a,int b){
  int faA=findFather(a);
  int faB=findFather(b);
  if(faA!=faB){
    father[faA]=faB;   // �ϲ���
  }
}

// ·��ѹ��--->�ҵ��ְֺ�˳�������ȫ���Ż���
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
    father[i]=i;  // ��ʼ�����нڵ�
  }

  // �����Ƿ���һ��������
  findFather(2)==findFather(4);
}
