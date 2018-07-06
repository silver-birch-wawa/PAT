#include <bits/stdc++.h>
using namespace std;
#define N 10000
int degree[N]={0};
int points,edges;
vector<vector<int>>v;
bool toposort(vector<vector<int>>&v){
    queue<int>q;
    int i,j;
    int counts=0;
    for(i=1;i<points+1;i++){
      if(degree[i]==0){
        q.push(i);
      }
    }
    while(!q.empty()){
      int pre=q.front();
      cout<<pre<<">>";
      q.pop();
      for(i=0;i<v[pre].size();i++){
        int choosed=v[pre][i];
        degree[choosed]--;
        if(degree[choosed]==0){
          q.push(choosed);
        }
      }
      counts++;
    }
    if(counts==counts){
      return true;
    }
    else{
      return false;
    }
}

int main(){
  int i,j;
  scanf("%d %d",&points,&edges);
  for(i=1;i<points+1;i++){
    vector<int>vv;
    v.push_back(vv);
  }
  int point1,point2;
  for(i=0;i<edges;i++){
    scanf("%d %d",&point1,&point2);
    v[point1].push_back(point2);
    degree[point2]++;
  }
  toposort(v);
}
/*
6 6
1 5
1 2
2 3
3 4
5 4
4 6
*/
