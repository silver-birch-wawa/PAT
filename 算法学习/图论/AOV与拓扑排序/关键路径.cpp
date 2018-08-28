#include <bits/stdc++.h>
using namespace std;
#define N 10000
int points,edges;
typedef struct{
  int num;
  int length;
  int l;
  int e;
}Node;
vector<vector<Node>>v;
bool occupy[N]={false};
int degree[N]={0};
// 最早ve和最晚vl
int ve[N]={0};
int vl[N]={0};

void mainpath(vector<vector<Node>>&v){
  vector<int>path;
  queue<int>p;
  int i,j;
  int mainlength=0;
  for(i=1;i<points+1;i++){
    if(degree[i]==0&&occupy[i]==false){
      occupy[i]=true;
      p.push(i);
    }
  }
  while(!p.empty()){
    int num=p.front();
    p.pop();
    path.push_back(num);
    //将路径写入path中

    // 从左往右选择最大的ve
    for(i=0;i<v[num].size();i++){
      int choosed=v[num][i].num;
      degree[choosed]--;
      // 修改ve[choosed]=ve[num]+mainlength
      ve[choosed]=max(ve[choosed],ve[num]+v[num][i].length);
      if(degree[choosed]==0){
        p.push(choosed);
        occupy[choosed]=true;
      }
    }
  }
  for(i=1;i<points+1;i++){
    vl[i]=ve[points];
    // 把所有vl设置为ve的最大值，最后一个ve。
  }

  int  times=path.size();
  // 把vector当作栈，从后往前遍历修改vl
  for(i=0;i<times;i++){
    int num=path.back();
    // pop节点
    path.pop_back();
    if(!v[num].empty()){
      // 对节点之后的节点vl[t]-length与v[num]比较,如果更小则替换v[num]。
      for(j=0;j<v[num].size();j++){
          int t=v[num][j].num;
          if(vl[num]>vl[t]-v[num][j].length){
            vl[num]=vl[t]-v[num][j].length;
          }
      }
    }
  }
  cout<<"-----------"<<endl;
  // 如果点A的ve==vl，则说明该点位于关键路径上。
  // 从start开始往下遍历
  int start=1;
  // 如果没有后继节点则停止
  while(!v[start].empty()){
    for(j=0;j<v[start].size();j++){
      if(ve[v[start][j].num]==vl[v[start][j].num]){
        cout<<start<<"->"<<v[start][j].num<<endl;
        mainlength+=v[start][j].length;
        start=v[start][j].num;
        break;
      }
    }
  }
  cout<<"Main length:"<<mainlength<<endl;
}
// 检查是否有重边。
bool check(vector<vector<Node>>&v,int point1,int point2){
  int i,j;
  for(i=0;i<v[point1].size();i++){
    if(v[point1][i].num==point2){
      return false;
    }
  }
  return true;
}
int main(){
  int i,j;
  scanf("%d %d",&points,&edges);
  for(i=1;i<points+1;i++){
    vector<Node>vv;
    v.push_back(vv);
  }
  int point1,point2,length;
  Node node;
  for(i=0;i<edges;i++){
    scanf("%d %d %d",&point1,&point2,&length);
    if(check(v,point1,point2)){
      node.num=point2;
      node.length=length;
      v[point1].push_back(node);
      degree[point2]++;
    }
  }
  mainpath(v);
}

/*
10 14
1 2 3
1 3 5
1 4 10
2 5 10
3 6 4
4 6 9
5 7 2
6 7 3
6 8 20
6 9 4
9 8 1
7 10 7
8 10 10
9 10 4

6 8
1 2 3
1 3 8
3 2 4
2 5 6
3 5 10
2 4 9
4 6 6
5 6 9
*/
