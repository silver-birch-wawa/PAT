#include <bits/stdc++.h>
using namespace std;
#define N 1000
struct Node{
  int length;
  int num;
};
bool occupy[N]={false};
// 点数，边数
int points,edges;
// 到已占领集合的距离
vector<vector<Node>>v;
void insert(vector<vector<Node>>&v,int point1,int point2,int length){
  Node n;
  n.length=length;
  n.num=point2;
  v[point1].push_back(n);
  n.num=point1;
  n.length=length;
  v[point2].push_back(n);
}
int prim(vector<vector<Node>>&v,int root){
  vector<int>s;
  int i,j;
  int dis=0;
  int parent=-1;
  s.push_back(root);
  occupy[root]=true;
  while(s.size()!=points){
    int min=N;
    int choose=-1;
    for(i=0;i<s.size();i++){
      int pre=s[i];
      for(j=0;j<v[pre].size();j++){
        int choosed=v[pre][j].num;
        if(occupy[choosed]==false){
          if(v[pre][j].length<min){
            min=v[pre][j].length;
            choose=choosed;
            parent=pre;
          }
        }
      }
    }
    if(choose==-1){
      return -1;
    }
    else{
      s.push_back(choose);
      dis+=min;
      occupy[choose]=true;
      cout<<parent<<">"<<choose<<endl;
      // cout<<"min:"<<min<<endl;
    }
  }
  return dis;
}
int main(){
  int i,j;
  scanf("%d %d",&points,&edges);
  for(i=0;i<points;i++){
    vector<Node>vv;
    v.push_back(vv);
  }
  int point1,point2,length;
  for(i=0;i<edges;i++){
    scanf("%d %d %d",&point1,&point2,&length);
    insert(v,point1,point2,length);
  }
  int root=0;
  int dis=prim(v,root);
  cout<<"distance:"<<dis<<endl;
}
/*
6 10
0 1 4
0 4 1
0 5 2
1 5 3
4 5 3
2 1 6
2 5 5
3 4 4
3 5 5
3 2 6
*/
