#include <bits/stdc++.h>
using namespace std;
typedef struct{
  int num;      // 在BFS中第一列[0]中作为记录上次遍历的位置
  int length;    // 长度
}Node;
const int INF=10000000;
#define N 200
int dis[N][N]={0};           // 记录到源点的距离
int points=0;                // 记录点数
int edges=0,begining,ending;

// 注意：样例输入是从1开始的不是2
void Floyd(){
  int i,j,k;
  for(k=1;k<points+1;k++){
    for(i=1;i<points+1;i++){
      for(j=1;j<points;j++){
        // if(i==j){
        //   // 不做不必要的修改，事实上不加这一行会出错
        //   continue;
        // }
        if(dis[i][k]!=INF&&dis[k][j]!=INF&&dis[i][k]+dis[k][j]<dis[i][j]){
          // 如果同步到i>j的一面会导致实际更改未被打印，所以要把左侧的结果同步到右侧。
          dis[i][j]=dis[i][k]+dis[k][j];
          dis[j][i]=dis[i][k]+dis[k][j];
        }
      }
    }
  }
}
// 为了减少打印操作，只打印右半边的数据
void show(){
  int i,j;
  for(i=1;i<points+1;i++){
    for(j=i+1;j<points+1;j++){
      if(dis[i][j]!=0)
      cout<<"("<<i<<","<<j<<")"<<dis[i][j]<<endl;
    }
  }
}
int main(){
  int i,j;
  scanf("%d %d",&points,&edges);
  for(i=1;i<points+1;i++){
    for(j=1;j<points+1;j++){
      dis[i][j]=INF;
    }
  }
  int point1,point2,length;
  for(i=0;i<edges;i++){
    scanf("%d %d %d",&point1,&point2,&length);
    dis[point1][point2]=length;
    dis[point2][point1]=length;
  }
  Floyd();
  show();
}

/*
4 5
1 2 1
1 3 2
1 4 3
2 4 1
3 4 2
*/
