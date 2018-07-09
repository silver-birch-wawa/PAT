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
    //cout<<"max ve:"<<ve[points-1];
  }
  int  times=path.size();
  for(i=0;i<times;i++){
    //cout<<path[i]<<" ";
    int num=path.back();
    path.pop_back();
    if(!v[num].empty()){
      for(j=0;j<v[num].size();j++){
          int t=v[num][j].num;
          //vl[num]=min(vl[t]-v[num][j].length,vl[num]);
          cout<<vl[t]-v[num][j].length<<"****"<<vl[num]<<endl;
          if(vl[num]>vl[t]-v[num][j].length){
            vl[num]=vl[t]-v[num][j].length;
            cout<<"pass"<<endl;
          }
      }
    }
  }
  // for(i=0;i<v.size();i++){
  //   for(j=0;j<v[i].size();j++){
  //     int num=v[i][j].num;
  //     v[i][j].e=ve[num];
  //     v[i][j].l=vl[num];
  //     cout<<"from:"<<i<<"to:"<<num<<endl;
  //     cout<<"ve:"<<ve[num]<<"   "<<"vl:"<<vl[num]<<endl;
  //   }
  // }
  cout<<"-----------"<<endl;
  int start=1;
  while(!v[start].empty()){
    for(j=0;j<v[start].size();j++){
      if(ve[v[start][j].num]==vl[v[start][j].num]){
        cout<<"from:"<<start<<"to:"<<v[start][j].num<<endl;
        start=v[start][j].num;
        break;
      }
    }
  }
}
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
*/
