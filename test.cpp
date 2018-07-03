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
int costs[N]={0};
int points=0;
int distances[N]={0};
bool occupy[N]={false};
vector<vector<Node>>v;
vector<vector<int>>fathers;
void insert(vector<vector<Node>>&v,int from,int to,int distance,int cost){
  Node n;
  n.distance=distance;
  n.cost=cost;
  n.num=to;
  v[from].push_back(n);
  n.num=from;
  v[to].push_back(n);
}
int min_length=100000;
int choose(vector<vector<Node>>&v,vector<int>path){
  int i=0,j=0;
  //int min_length=100000;
  int choosed=-1;
  int parent=-1;
  int son=-1;
  vector<int>parents;
  for(i=0;i<path.size();i++){
    int p=path[i];
    for(j=0;j<v[p].size();j++){
      int next=v[p][j].num;
      if(!occupy[next]){
        if(min_length>v[p][next].distance+distances[p]){
          parents.clear();
          parent=p;
          son=next;

          parents.push_back(p);
          choosed=next;
          distances[next]=v[p][next].distance+distances[p];
        }
        else if(min_length==v[p][next].distance+distances[p]){
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
}
vector<int>ans;
void Dijkstra(vector<vector<Node>>v,int begin,int end){
  int i,j;
  vector<int>path;
  path.push_back(begin);
  occupy[begin]=true;
  int min_cost=10000;
  //int min_length
  while(path.size()!=points){
    int choosed=choose(v,path);
    if(choosed==-1){
      break;
    }
    else if(choosed==end){
      path.push_back(choosed);
      int cost=0;
      for(i=0;i<path.size()-1;i++){
        cost+=v[path[i]][path[i+1]].cost;
      }
      if(cost<min_cost){
        ans=path;
        min_cost=cost;
      }
    }
    else{
      path.push_back(choosed);
    }
  }
  for(i=0;i<ans.size();i++){
    cout<<ans[i]<<" ";
  }
  cout<<min_length<<" "<<min_cost;
}
int main(int argc, char const *argv[]) {
  int edges;
  int begin;
  int end;
  scanf("%d %d %d %d",&points,&edges,&begin,&end);
  int i,j;
  int from,to,distance,cost;
  for(j=0;j<points;j++){
    vector<Node>vv;
    v.push_back(vv);
    vector<int>t;
    fathers.push_back(t);
  }
  for(i=0;i<edges;i++){
    scanf("%d %d %d %d",&from,&to,&distance,&cost);
    insert(v,from,to,distance,cost);
  }
  Dijkstra(v,begin,end);
  return 0;
}
