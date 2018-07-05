#include <bits/stdc++.h>
using namespace std;
#define N 1000
struct edge{
  int from,to;
  int length;
  bool occupy;
  edge(){
    length=0;
    from=0;
    to=0;
    occupy=false;
  }
}E[N];
// 点数，边数
int points,edges;
// 并查集的fathers
int fathers[N];

// 把边根据权值进行排序
bool cmp(edge a,edge b){
  return a.length<b.length;
  // 从小到大排序
}

int findfather(int x){
  int fa=x;
  while(fathers[x]!=x){
    x=fathers[x];
  }
  while(fathers[fa]!=fa){
    fa=fathers[fa];
    fathers[fa]=x;
  }
  return x;
}

void merge(int a,int b){
  int faa=findfather(a);
  int fab=findfather(b);
  // 不是fathers[a]=fab，是把a和b的father统一。
  fathers[faa]=fab;
  cout<<"merge: "<<a<<">"<<b<<endl;
}

int kruskal(){
  int ans=0;
  int i;
  // 最短路径长度
  int counts=0;
  // 当前占领的边数
  bool s;
  // 退出循环的条件是加入的边数等于点数-1，这是最小生成树的特征之一
  while(counts!=points-1){
    s=false;
    // 用edges不要用points，kruskla是围绕着边进行的。
    for(i=0;i<edges;i++){
      if(E[i].occupy==false){
        // 不能用fathers，在合并的时候可能会有二级跳转，findfather可能是一致的但是fathers会不同。
        if(findfather(E[i].from)!=findfather(E[i].to)){
          merge(E[i].from,E[i].to);
          ans+=E[i].length;
          // 计算最小生成树的总长度
          E[i].occupy=true;
          // 这条边被占用
          s=true;
          // 如果没有可以加入的边了就标记一下，避免陷入死循环。
          counts++;
          // 加入的边数目++
          break;
        }
      }
    }
    if(s==false){
      return -1;
    }
  }
  return ans;
}
int main(){
  int i,j;
  scanf("%d %d",&points,&edges);
  int point1,point2,length;
  for(i=0;i<edges;i++){
    scanf("%d %d %d",&point1,&point2,&length);
    fathers[i]=i;
    E[i].from=point1;
    E[i].to=point2;
    E[i].length=length;
  }
  sort(E,E+edges,cmp);
  int ans=kruskal();
  cout<<"\nMST length:"<<ans<<endl;
}

/*
6 10
0 1 4
0 4 1
0 5 2
1 5 3
4 5 3
2 1 1
2 5 5
3 4 5
3 5 4
3 2 6
*/
