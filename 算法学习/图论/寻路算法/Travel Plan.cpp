#include <bits/stdc++.h>
using namespace std;
typedef struct{
  int num;      // 在BFS中第一列[0]中作为记录上次遍历的位置
  int distance;    // 长度
  int cost;
  //bool isOccupy;
  // 在邻接表中用于避免BFS重复遍历，永久标记。第一列作为完全遍历的标记
}Node;
#define N 10000
int costs[N][N]={0};
int dis[N][N]={0};
// 记录边的权重,在DFS中有用,邻接表无法解决边权的访问，因为一个点对应一个点权，但对应多个边权。

int points=0;
// 记录点数

int distances[N]={0};
// 用于在Dijskla中记录

bool occupy[N]={false};
// 标记占领

vector<vector<Node>>v;
vector<vector<int>>fathers;
void insert(vector<vector<Node>>&v,int from,int to,int distance,int cost){
  Node n,m;
  n.distance=distance;
  n.cost=cost;
  n.num=to;
  v[from].push_back(n);
  n.num=from;
  v[to].push_back(n);
}
int choose(vector<vector<Node>>&v,vector<int>path){
  int i=0,j=0;
  int min_length=10000;
  int choosed=-1;
  int parent=-1;
  int son=-1;
  vector<int>parents;
  for(i=0;i<path.size();i++){
    int p=path[i];
    for(j=0;j<v[p].size();j++){
      int next=v[p][j].num;
      if(!occupy[next]){
        if(min_length>v[p][j].distance+distances[p]){
          min_length=v[p][j].distance+distances[p];
          parents.clear();
          parent=p;
          son=next;

          choosed=next;
          distances[next]=v[p][j].distance+distances[p];
        }
        else if(min_length==v[p][j].distance+distances[p]){
          if(next==son){
            parents.push_back(p);
          }
        }
      }
    }
  }
  if(choosed!=-1){
    occupy[choosed]=true;
    fathers[son].push_back(parent);
    for(i=0;i<parents.size();i++){
      fathers[son].push_back(parents[i]);
    }
  }
  return choosed;
}
vector<int>ans;
int begining;
int ending;
// 不要用begin/end，会报错
int ans_cost=100000;
int ans_length=100000;

void DFS(vector<vector<Node>>&v,vector<int>&t,int start,int& min_length,int& min_cost){
  // 在DFS时每加入一个节点就+=一次cost/length
  int i,j;
  if(start==begining){
    if(ans_length>min_length){
      ans_length=min_length;
    }
    if(ans_cost>min_cost){
      ans_cost=min_cost;
      ans=t;
    }
    return;
  }
  for(i=fathers[start].size()-1;i>=0;i--){
    t.push_back(fathers[start][i]);
    min_length+=dis[start][fathers[start][i]];
    min_cost+=costs[start][fathers[start][i]];
    DFS(v,t,fathers[start][i],min_length,min_cost);
    min_length-=dis[start][fathers[start][i]];
    min_cost-=costs[start][fathers[start][i]];
    t.pop_back();
  }
}
void Dijkstra(vector<vector<Node>>&v,int begining,int ending){
  int i,j;
  vector<int>path;
  path.push_back(begining);
  occupy[begining]=true;
  int min_cost=0;
  int min_length=0;
  while(path.size()!=points){
    int choosed=choose(v,path);
    if(choosed==-1){
      break;
    }
    else{
      path.push_back(choosed);
    }
  }
  vector<int>t;
  t.push_back(ending);
  DFS(v,t,ending,min_length,min_cost);
  for(i=ans.size()-1;i>=0;i--){
    cout<<ans[i]<<" ";
  }
  cout<<ans_length<<" "<<ans_cost;
}
int main(int argc, char const *argv[]) {
  int edges;
  scanf("%d %d %d %d",&points,&edges,&begining,&ending);
  int i,j;
  int from=0,to=0,distance=0,cost=0;
  for(j=0;j<points;j++){
    vector<Node>vv;
    v.push_back(vv);
    vector<int>t;
    fathers.push_back(t);
  }
  for(i=0;i<edges;i++){
    scanf("%d %d %d %d",&from,&to,&distance,&cost);
    costs[from][to]=cost;
    costs[to][from]=cost;
    dis[from][to]=distance;
    dis[to][from]=distance;
    insert(v,from,to,distance,cost);
  }
  Dijkstra(v,begining,ending);
  return 0;
}
