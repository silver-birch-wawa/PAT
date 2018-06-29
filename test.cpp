#include <bits/stdc++.h>
using namespace std;
typedef struct{
  int num;      // 在BFS中第一列[0]中作为记录上次遍历的位置
  int value;    // 长度
  int people;
  //bool isOccupy;
  // 在邻接表中用于避免BFS重复遍历，永久标记。第一列作为完全遍历的标记
}Node;
#define N 1000
vector<vector<Node>>v;
int points=0;   // 记录点数
int dis[N]={0};
bool occupy[N]={0};
void insert(vector<vector<Node>>&v,int point1,int point2,int length){
  Node node;
  node.num=point1;
  node.value=length;
  v[point2].push_back(node);
  node.num=point2;
  v[point1].push_back(node);
}
int choose(vector<vector<Node>>&v,vector<int>q){
  int i,j;
  int min_length=1000000;
  int choosed=-1;
  for(j=0;j<q.size();j++){
    int point=q[j];
    for(i=0;i<v[point].size();i++){
      if(occupy[v[point][i].num]==false){
        if(v[point][i].value+dis[point]<min_length){
          min_length=v[point][i].value;
          choosed=v[point][i].num;
        }
      }
    }
  }
  if(choosed!=-1){
    occupy[choosed]=true;
  }
  return choosed;
}
void Dijkstra_improve(vector<vector<Node>>&v,int begin,int end,int numbers,int max_group){
  int i,j;
  int choosed;
  vector<int>q;
  q.push_back(begin);
  occupy[begin]=true;
  while(q.size()!=points){
    choosed=choose(v,q);
    if(choosed==-1){
      break;
    }
    else{
      cout<<">>"<<choosed<<"  ";
      q.push_back(choosed);
    }
  }
}
int main(){
  int edges,point;
  int begin,end;
  scanf("%d %d %d %d",&points,&edges,&begin,&end);
  int i,j;
  for(i=0;i<points;i++){
    scanf("%d",&point);
    vector<Node>vv;
    v.push_back(vv);
  }
  int point1,point2,length;
  for(i=0;i<edges;i++){
    scanf("%d %d %d",&point1,&point2,&length);
    Node node;
    insert(v,point1,point2,length);
  }
  int numbers;
  int max_group;
  Dijkstra_improve(v,begin,end,numbers,max_group);
  cout<<"end......"<<endl;
}


/*
7 8
1 2 7
1 4 5
2 3 12
4 5 3
4 6 4
5 7 4
6 7 3
7 3 5


9 12
1 2 3
1 3 4
1 4 6
2 5 7
3 5 6
4 5 4
5 6 3
5 7 2
5 8 1
6 9 4
7 9 5
8 9 6
*/
