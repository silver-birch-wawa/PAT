#include <bits/stdc++.h>
using namespace std;
#define N 10000
// 原题是要求一次输入一次输出
int degree[N]={0};
bool occupy[N]={false};
int points=0,edges;
void toposort(vector<vector<int>>&v){
  priority_queue<int,vector<int>,greater<int>>p;
  vector<int>ans;
  int i,j;
  while(1){
    for(i=1;i<points+1;i++){
      if(degree[i]==0&&occupy[i]==false){
          p.push(i);
          counts++;
          occupy[i]=true;
      }
    }
    if(p.size()==0){
      // 当没有新节点时break
      break;
    }
    //穷举degree为0的子节点，如果degree--为0，则加入queue
    while(!p.empty()){
      int num=p.top();
      p.pop();
      // ans将作为输出的结果加入queue
      ans.push_back(num);
      if(!v[num].empty()){
        for(i=0;i<v[num].size();i++){
          int choosed=v[num][i];
          degree[choosed]--;
          //一开始没有考虑到把后面degree为0的情况考虑进去
          if(degree[choosed]==0){
            p.push(choosed);
            occupy[choosed]=true;
          }
        }
      }
    }
  }
  cout<<"output: ";
  cout<<ans[0];
  for(i=1;i<ans.size();i++){
    cout<<" "<<ans[i];
  }
  cout<<endl;
}
// 检查是否有重边出现
bool check(vector<vector<int>>&v,int point1,int point2){
  int i,j;
  for(i=0;i<v[point1].size();i++){
    if(v[point1][i]==point2){
      return false;
    }
  }
  return true;
}
int main(){
  int i,j,n,m;
  int point1,point2;
  while(scanf("%d %d",&n,&m)){
    vector<vector<int>>v;
    for(i=0;i<n+1;i++){
      vector<int>vv;
      v.push_back(vv);
    }
    if(n==0&&m==0){
      // 输入 0 0 时退出程序
      break;
    }
    for(i=0;i<m;i++){
      scanf("%d %d",&point1,&point2);
      // 如果有重边的话会导致degree++从而出现问题，所以需要去一次重。
      if(check(v,point1,point2)){
        v[point1].push_back(point2);
        degree[point2]++;
        points=n;
      }
    }
    toposort(v);
    v.clear();
    for(i=0;i<points+1;i++){
      occupy[i]=false;
      degree[i]=0;
    }
    // 一次输入对应一次输出，所以要清空
  }
}

/*
3 2
3 1
3 2
17 16
16 1
13 2
7 3
12 4
12 5
17 6
10 7
11 8
11 9
16 10
13 11
15 12
15 13
17 14
17 15
17 16
0 0
*/
