#include <bits/stdc++.h>
using namespace std;
#define N 10000
int degree[N]={0};
bool occupy[N]={false};
int points,edges;
vector<vector<int>>v;
void show(priority_queue<int,vector<int>,greater<int>>q){
  // 不需要传引用，相当于用拷贝的内存换取了pop的时间
  int i;
  int times=q.size();
  int num;
  for(i=0;i<times;i++){
    num=q.top();
    q.pop();
    cout<<">>"<<num;
    //q.pop_back();
  }
  cout<<endl;
}
bool toposort(vector<vector<int>>&v){
    priority_queue<int,vector<int>,greater<int>>q;
    // 利用priority_queue自带的排序功能
    int i,j;
    int counts=0;

    while(1){
      for(i=1;i<points+1;i++){
        if(degree[i]==0&&occupy[i]==false){
          q.push(i);
          occupy[i]=true;
        }
      }
      if(q.size()==0){
        break;
        // 避免queue为空陷入死循环
      }
      // 进行第一层遍历的时候进行排序然后show()输出
      int start=q.size();
      show(q);

      // 在第一层进行
      for(i=0;i<start;i++){
        int pre=q.top();;
        q.pop();
        counts++;

        if(!v[pre].empty()){
          // 很奇怪，使用vector<vector>的时候如果v[i]为empty
          for(j=0;j<v[pre].size();j++){
            int choosed=v[pre][j];
            degree[choosed]--;
          }
        }
      }
    }
    if(counts==points){
      return true;
    }
    else{
      return false;
    }
}

int main(){
  int i,j;
  scanf("%d %d",&points,&edges);
  for(i=0;i<points+1;i++){
    vector<int>vv;
    v.push_back(vv);
  }
  int point1,point2;
  for(i=0;i<edges;i++){
    scanf("%d %d",&point1,&point2);
    v[point1].push_back(point2);
    degree[point2]++;
  }
  if(toposort(v)){
    cout<<"pass"<<endl;
  }

}

/*
7 7
1 5
1 2
1 7
2 3
3 4
5 4
4 6

*/
