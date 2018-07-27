#include <bits/stdc++.h>
using namespace std;
typedef struct{
  int num;      // 在BFS中第一列[0]中作为记录上次遍历的位置
  int value;    // 长度
  int people;
  //bool isOccupy;
  // 在邻接表中用于避免BFS重复遍历，永久标记。第一列作为完全遍历的标记
}Node;
#define N 10000
vector<vector<Node>>v;
vector<vector<int>>parent;
int points=0;   // 记录点数
int dis[N]={0};
bool occupy[N]={0};

int saver[N]={0};

// 记录每个点对应的父节点
void record(vector<vector<int>>&v,int father,int son){
  v[son].push_back(father);
}
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
  // 选一个非常大的数作为最短路径的初始值
  //int min_length=100000;
  int min_length=0x7fffffff;
  // 天选之子
  int choosed=-1;
  // 到起始点的最优距离
  int distance=0;
  // 记录父子关系
  int record_father=0;
  int record_son=0;

  vector<int>fathers;// 这一轮遍历下来你可能会有很多爸爸

  for(j=0;j<q.size();j++){
    int point=q[j];
    for(i=0;i<v[point].size();i++){
      if(occupy[v[point][i].num]==false){
        // 如果有更短路径，
        if(v[point][i].value+dis[point]<min_length){
          // 更新最短长度
          min_length=v[point][i].value+dis[point];
          // 更新当前最优节点
          choosed=v[point][i].num;
          // 更新到起始点的最短距离
          distance=v[point][i].value+dis[point];
          // 建立父子关系
          record_son=choosed;
          record_father=point;

          // 改了就不认以前的爸爸们了
          fathers.clear();
        }
        // 对路径长度相同的父节点进行记录，添加到parent中
        else if(v[point][i].value+dis[point]==min_length){
          // 对于最小距离节点进行切换的情况需要clear,不换的话就把二爸爸三爸爸放fathers[]里存起来
          if(v[point][i].num==choosed){
            // 在加入新节点的时候要注意儿子要一样，因为爸爸们要放在同一个儿子的节点的记录上
            // 书上是不管三七二十一加到parent上，反正最短的时候会清零。
            fathers.push_back(point);
          }
        }
      }
    }
  }
  if(choosed!=-1){
    // 固定最优距离
    dis[choosed]=distance;
    // 标记占领
    occupy[choosed]=true;
    // 把二爸爸们记录在parent[]里面
    for(i=0;i<fathers.size();i++){
      record(parent,fathers[i],record_son);
    }
    // 把爸爸记录在parent[]里面
    record(parent,record_father,record_son);
  }
  return choosed;
}
//
void Dijkstra_improve(vector<vector<Node>>&v,int begining,int ending,int numbers){
  int i,j;
  int choosed;
  // 存储已占领节点
  vector<int>q;
  // 初始化栈
  q.push_back(begining);
  // 标记占领起点
  occupy[begining]=true;
  // 当栈没有装满所有节点
  while(q.size()!=points){
    // 选择一个天选之子
    choosed=choose(v,q);
    // 选不出来就算了,宣布寻路结束
    if(choosed==-1){
      break;
    }
    // 选出来的话就入栈
    else{
      // cout<<">>choosed:"<<choosed<<"  \n";
      q.push_back(choosed);
    }
  }

}
// 打印路径
void show(vector<int>&s){
  int i;
  for(i=s.size()-1;i>=0;i--){
    cout<<">>"<<s[i];
  }
  cout<<endl;
}
int begining=0;
int ending=0;

// 计算救援人员的最大个数
void calcmax(vector<int>&s,int& max_calc){
  int might=0,i;
  for(i=s.size()-1;i>=0;i--){
    //cout<<">>"<<s[i];
    might+=saver[s[i]];
  }
  if(might>max_calc){
    max_calc=might;
  }
}
// 根据parent列表，从end到begin自底向上DFS遍历
void DFS_Path(vector<vector<int>>&parent,vector<int>&s,int start,int& max_group,int& max_calc){
    // 堆栈用来存储DFS的路径
    int i,j;
    // 触底
    if(start==begining){
      max_group++;
      //s.push_back(begining);
      //show(s);
      // clacmax(s,max_calc);
      int might=0;
      for(i=s.size()-1;i>=0;i--){
        //cout<<">>"<<s[i];
        might+=saver[s[i]];
      }
      if(might>max_calc){
        max_calc=might;
      }
      //s.pop_back();
      return;
    }
    // 未触底
    for(i=0;i<parent[start].size();i++){
      s.push_back(parent[start][i]);
      DFS_Path(parent,s,parent[start][i],max_group,max_calc);
      s.pop_back();
    }
}
int main(){
  int edges,point;
  scanf("%d %d %d %d",&points,&edges,&begining,&ending);
  int i,j;
  for(i=0;i<points;i++){
    dis[i]=0;
    scanf("%d",&point);
    saver[i]=point;

    vector<Node>vv;
    v.push_back(vv);
    vector<int>p;
    parent.push_back(p);
  }
  int point1,point2,length;
  for(i=0;i<edges;i++){
    scanf("%d %d %d",&point1,&point2,&length);
    Node node;
    insert(v,point1,point2,length);
  }

  // 用于统计急救队的人数
  int numbers;

  // 使用优化了的Dijkstra获取 fathers[]还有最近路径dis[]
  Dijkstra_improve(v,begining,ending,numbers);

  // 栈递归前的初始化准备,该栈用于存储路径
  vector<int>s;
  s.push_back(ending);

  int max_group=0;
  int max_calc=0;
  // 统计相同长度的路径数量还有所经过的节点数，在DFS递归的时候统计同长度路径的个数个数
  DFS_Path(parent,s,ending,max_group,max_calc);
  cout<<max_group<<" "<<max_calc<<endl;
}

/*

9 12 0 8
1 2 1 5 3 1 2 1 5
0 1 3
0 2 4
0 3 6
1 4 7
2 4 6
3 4 4
4 5 3
4 6 2
4 7 1
5 8 4
6 8 5
7 8 6

*/
