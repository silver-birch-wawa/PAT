#include<bits/stdc++.h>
using namespace std;
// 第一行输入n和m告诉你点数还有输入循环的次数
// （一个父节点后面可以跟很多子节点）
#define N 10000
int n=0;
bool occupy[N]={false};
int degree[N]={0};
// i节点的子节点个数
int fathers[N]={0};

// 把所有以num为父节点的都放入里面
void add(queue<int>&q,int num){
  int i,j;
  for(i=1;i<n+1;i++){
    if(fathers[i]==num){
      q.push(i);
    }
  }
}
// i节点的父节点
void BFSsearch(queue<int>&q){
  int length=q.size();
  if(length==0){
    return;
  }
  int i,j,counts=0;
  for(i=0;i<length;i++){
    int t=q.front();
    q.pop();
    if(degree[t]==0){
      counts++;
    }
    add(q,t);
  }
  cout<<" "<<counts;
  BFSsearch(q);
}
int main(){
  int i,j,m;
  scanf("%d %d",&n,&m);
  int father,son,k;
  for(i=0;i<m;i++){
    scanf("%d %d",&father,&k);
    for(j=0;j<k;j++){
      scanf("%d",&son);
      fathers[son]=father;
      degree[father]++;
    }
  }
  int counts=0;
  queue<int>q;
  for(i=1;i<n+1;i++){
    if(fathers[i]==1)
    {
      counts++;
      //cout<<i<<":"<<fathers[i]<<endl;
      q.push(i);
    }
  }
  if(counts==0){
    cout<<1;
  }
  else{
    cout<<0;
  }
  BFSsearch(q);
}
