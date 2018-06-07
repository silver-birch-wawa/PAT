#include <bits/stdc++.h>
using namespace std;
int maxvalue;
vector<vector<int> >v;
int volumn=0;
// 对于V溢出要允许回退，但是对于index溢出绝对不允许。
void DFS(int index,int sumV,int sumC){
  if(index==v.size()){  // 如果遍历结束则返回。
    //cout<<"index break"<<endl;
    return;
  }
  int V=sumV+v[index][1];
  int C=sumC+v[index][0];   // 尝试性添加，失败就回退（不添加）。
  //cout<<"v.size"<<v.size()<<endl;
  //cout<<index<<":"<<V<<":"<<C<<":"<<maxvalue<<endl;
  //cout<<"vvvv:"<<volumn<<endl;
  DFS(index+1,sumV,sumC);    // 无论如何不添加都是可以的，不可以放if...else里面。因为溢出了还能回退（不添加）。
  if(volumn>=V){
      if(C>maxvalue){
        maxvalue=C;
        //cout<<"maxv:"<<maxvalue;
      }
      DFS(index+1,V,C);     // 添加后不溢出就添加。
  }
  else{      // 体积超出则返回,但是不能放在前面，因为可能回退后再DFS(index+1,sumV,sumC)后还有解。
      //cout<<"volumn break"<<endl;
      return;
  }
}
int main(){
  maxvalue=0;
  int number,weight,value;
  scanf("%d %d",&number,&volumn);

  int i;
  vector<int>vv;

  for(i=0;i<number;i++){
    scanf("%d",&value);
    vv.push_back(value);
    v.push_back(vv);
    vv.clear();
  }
  for(i=0;i<number;i++){
    scanf("%d",&weight);
    v[i].push_back(weight);
  }

  int index=0,sumV=0,sumC=0;
  DFS(index,sumV,sumC);
  cout<<maxvalue<<endl;
  //cout<<"end....."<<endl;
}
