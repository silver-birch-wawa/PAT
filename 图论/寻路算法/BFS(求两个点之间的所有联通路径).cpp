#include <bits/stdc++.h>
using namespace std;
typedef struct{
  int num;
  // 在BFS中第一列v[i][0].num中作为记录上次遍历的位置
  int value;
  // 长度等权值
}Node;

#define N 1000
bool isOccupy[N]={false};
// 防回环的临时标记，用于当前BFS前进试错中选中的节点标记，在pop栈后恢复为false。

int choose(vector<vector<Node>>&v,int points){
  int i=0;
  int choosed=-1;

  // 之前遍历结束时v[points][0].num置为满，回退的过程中抑制延伸返回-1，把突出部位回退。
  // 但是当从别的路径遍历过来的时候v[points][0].num需要恢复为0。
  // 这样的标记设计避免了bool的使用而且记住了上一次操作的位置

  for(i=v[points][0].num+1;i<v[points].size();i++){
    // 跳过之前遍历过的节点（从0->length遍历，所以i+1就可以跳过之前的所有节点）
    if(isOccupy[v[points][i].num]==false){
          choosed=v[points][i].num;
          // 修改临时占领标记
          isOccupy[choosed]=true;
          // 标记当前遍历到的节点位置，下一次就从下一个节点开始遍历
          v[points][0].num=i;

          // 对于需要再遍历的下一个节点，需要把它的内部指针调回0
          if(v[choosed][0].num==v[choosed].size()-1)
          {
            v[choosed][0].num=0;
          }
          break;  //找到第一个就应该跳出循环了
    }
  }
  return choosed;
}
void print(vector<int>s){
  int i;
  for(i=0;i<s.size();i++){
    cout<<">>"<<s[i];
  }
  cout<<endl;
}
// BFS的栈回退操作
void pop_back(vector<int>&s){
  int t=s[s.size()-1];
  // cout<<"\n#####pop:"<<t<<endl;
  isOccupy[t]=false;
  s.pop_back();
}

void BFS_path(vector<vector<Node>>&v,int start,int end){
  vector<int>s;  // 用stack模拟栈
  s.push_back(start);
  int path_length=0;

  int points,choosed;
  // 栈不为空时
  while(!s.empty()){
    int points=s[s.size()-1];
    // 取栈顶元素
    choosed=choose(v,points);
    //cout<<"\n!!!! choosed:"<<choosed<<endl;
    // 在触底的时候
    if(choosed==end){
      s.push_back(choosed);
      print(s);
      pop_back(s);
      isOccupy[choosed]=false;
    }
    // 在陷入死胡同的时候就需要回退到正确的路上
    else if(choosed==-1){
      pop_back(s);
    }
    // 在未到达终点的时候
    else{
      s.push_back(choosed);
    }
  }
}
int main(){
  vector<vector<Node>>v;
  // 用来存储已占领的节点，用于后面遍历邻接未占领节点
  // 第一行废弃，第二行开始第一列用于标记是否后续已占满，只有后面用于记录value边权值还有num后继节点
  int edges,i,j,points;
  scanf("%d %d",&points,&edges);

  // 初始化第一列的链
  for(i=0;i<points+1;i++){
    vector<Node>vv;
    v.push_back(vv);
    Node node;
    node.num=0;
    node.value=0;
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
  int end=9;
  isOccupy[start]=true;
  BFS_path(v,start,end);
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
