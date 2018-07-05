#include <bits/stdc++.h>
using namespace std;
typedef struct{
  int num;
  int value;
  bool isfull;
}Node;
bool sign[1000]={false};  // 是否已被占领
int dis[1000]={0};   // 距离矩阵
int points=0;   // 点的个数

// 如果是无向图（可双向行驶），所以需要两边填充，a到b和b到a
// 但是这个例子是单向有向图，所以不需要
int choose(vector<vector<Node>>v,queue<int>q){
  int i,j,choosed=-1;        // 最佳节点初始为一个不存在的-1，方便查找失败的判断
  int min_value=1000000000;  // 选一个最大值作为初始最小值，这样才好比较式替换
  while(!q.empty()){
    int head=q.front();
    q.pop();
    if(v[head][0].isfull==false){
      bool isfull=true;     // 如果都已经占领，下次就不用再遍历了
      for(i=1;i<v[head].size();i++){
          // 对所有已占领节点可以直达(相邻)的节点（sign==false）遍历，看看能否找到最短的直连路径然后将其占领（return choosed;）
          if(sign[v[head][i].num]==false){
            isfull=false;
            // 有活节点标记，isfull标记用

            // value+最近已占领节点的dis[head]如果更小则替换最佳节点和min_value
            if(dis[head]+v[head][i].value<min_value){
              choosed=v[head][i].num;
              min_value=dis[head]+v[head][i].value;
            }
          }
      }
      if(isfull==true){
        v[head][0].isfull=true;   // 整个图一个空的都没有，满了isfull=true
      }
    }
  }
  if(choosed==-1){
    return -1;  // 很遗憾，并不是所有节点都可以占领
  }
  sign[choosed]=true;   // 很幸运，你占领了一个新节点，在sign上做个标记然后吧distance写入dis数组
  dis[choosed]=min_value;
  return choosed;
}
void show(){
  int i,j;
  for(i=1;i<points+1;i++){
    cout<<"sign:"<<sign[i]<<"  ";
  }
  cout<<endl;
  for(i=1;i<points+1;i++){
    cout<<"dis:"<<dis[i]<<"   ";
  }
  cout<<endl;
}
void DFS(vector<vector<Node>>v,int start){
  queue<int>q;
  q.push(start);
  int i,j;
  int choosed=0;  // 选中哪个节点作为天选之子

  while(q.size()!=points){
        choosed=choose(v,q);
        cout<<"\nchoosed:"<<choosed<<endl;
        cout<<"value:"<<dis[choosed]<<endl;
        if(choosed!=-1){
          q.push(choosed);
          // 把天选之子放入队列，以后遍历需要用
        }
        else{
          // 为-1说明有节点不可达~，看最后输出的dis是否为0即可判断
          break;
        }
  }
}
int main(){
  vector<vector<Node>>v;
  // 用来存储已占领的节点，用于后面遍历邻接未占领节点
  // 第一行废弃，第二行开始第一列用于标记是否后续已占满，只有后面用于记录value边权值还有num后继节点
  int edges,i,j;
  scanf("%d %d",&points,&edges);
  //
  for(i=0;i<points+1;i++){
    vector<Node>vv;
    v.push_back(vv);
    Node node;
    node.num=0;
    node.value=0;
    node.isfull=false;
    v[i].push_back(node);
  }
  int a,b,value;
  for(j=0;j<edges;j++){
    scanf("%d %d %d",&a,&b,&value);
    Node node;
    node.num=b;
    node.value=value;
    v[a].push_back(node);
  }

  int start=1;
  DFS(v,start);
}

/*
6 9
1 2 1
1 3 12
2 3 9
2 4 3
3 5 5
4 3 4
4 5 13
4 6 15
5 6 4
*/
