#include <bits/stdc++.h>
using namespace std;
typedef struct{
  int num;      // 在BFS中第一列[0]中作为记录上次遍历的位置
  int length;    // 长度
}Node;
#define N 100000
int dis[N]={0};           // 记录到源点的距离
bool occupy[N]={false};   // 是否在queue中
int counts[N]={0};        // 计算同一个节点的入栈次数，>=n即有负环出现，return ;
int points=0;             // 记录点数
int edges=0,begining,ending;
vector<vector<Node>>v;
// 思路：BFS暴力穷举所有的边，进行全局优化。
int bellman(vector<vector<Node>>v,int begining){
  int i=0,j=0;
  queue<int>q;
  q.push(begining);
  counts[begining]++;
  // 入栈时访问计数器++

  while(!q.empty()){
    int t=q.front();
    q.pop();
    occupy[t]=false;
    // 标记为出栈

    for(i=0;i<v[t].size();i++){
      int choosed=v[t][i].num;
      if(!occupy[choosed]){
        int distance=dis[t]+v[t][i].length;
        if(dis[choosed]>distance){
          occupy[choosed]=true;
          // 标记入栈
          q.push(choosed);
          counts[choosed]++;
          // 入栈计数器++
          dis[choosed]=distance;
          // 更新路径

          // 入栈次数>=点数则报错
          if(counts[choosed]>=points){
            return 2;
          }
        }
      }
    }
  }
  return 1;
}
void insert(vector<vector<Node>>&v,int point1,int point2,int length){
  Node node;
  node.num=point2;
  node.length=length;
  v[point1].push_back(node);
}
int main(){
  int i,j;
  scanf("%d %d %d %d",&points,&edges,&begining,&ending);
  int point1,point2,length;
  for(i=0;i<points;i++){
    dis[i]=N;
    vector<Node>vv;
    v.push_back(vv);
  }
  dis[begining]=0;
  // 起始点的距离设为0，其他设为无穷大。
  for(i=0;i<edges;i++){
    scanf("%d %d %d",&point1,&point2,&length);
    //Node node;
    insert(v,point1,point2,length);
  }
  int ans=bellman(v,begining);
  cout<<"ans:"<<ans<<endl;
  if(ans==2){
    cout<<"Has negative ring!"<<endl;
    return 0;
  }
  cout<<"-------"<<endl;
  for(i=0;i<points;i++){
    cout<<">>>"<<dis[i]<<" ";
  }
}

/*
3 3 0 2
0 1 5
1 2 3
2 0 -10
*/
