#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<map>
using namespace std;
#define N 1000
int fathers[N]={0};
int findfather(int s){
  int t=s;
  int f;
  while(fathers[t]!=t){
    t=fathers[t];
  }
  f=t;
  t=s;
  while(fathers[t]!=t){
    fathers[t]=f;
    t=fathers[t];
  }
  return f;
}
void merge(int a,int b){
  int f1=findfather(a);
  int f2=findfather(b);
  fathers[f2]=f1;
}
void deal(vector<vector<int>>v,int line){

}
int main(){
  vector<vector<int>>v;
  int i,j;
  map<int,int>m;
  while(1){
    char p=getchar();
    if(p=='\n'){
      break;
    }
    else{
      vector<int>vv;
      v.push_back(vv);
      v[v.size()-1].push_back(p-'0');
    }
    while(1){
      char c=getchar();
      if(c=='\n'){
        break;
      }
      v[v.size()-1].push_back(c-'0');
    }
    //getchar();
  }
  if(v.size()==0){
    cout<<0;
    return 0;
  }
  int width=v[0].size(),height=v.size();
  // fathers进行调整
  for(i=0;i<width*height;i++){
    fathers[i]=i;
  }
  // cout<<width<<"   "<<height<<endl;
  if(v[0][0]==v[0][1]&&v[0][0]==1){
    merge(0,1);
  }
  for(i=1;i<width;i++){
    if(v[0][i]==v[0][i-1]&&v[0][i]==1){
      merge(i,i-1);
    }
  }
  for(i=1;i<height;i++){
    if(v[i][0]==v[i][1]&&v[i][0]==1){
      merge(i*width+0,i*width+1);
    }
    for(j=1;j<width;j++){
      if(v[i][j]==1){
        if(v[i][j]==v[i][j-1]){
          merge(i*width+j,i*width+j-1);
        }
        if(v[i][j]==v[i-1][j]){
          merge(i*width+j,(i-1)*width+j);
        }
      }
    }
  }
  // 统计岛屿的大小还有根节点的位置
  for(i=0;i<height;i++){
    for(j=0;j<width;j++){
      if(v[i][j]==1){
        int f=findfather(i*width+j);
        if(m.count(f)){
          m[f]++;
        }
        else{
          m[f]=1;
        }
      }
    }
  }
  cout<<"Number of islands: "<<m.size()<<endl;
  for(map<int,int>::iterator it=m.begin();it!=m.end();it++){
     cout<<"Start position: ("<<it->first/width<<","<<it->first%width<<")   scale:"<<it->second<<endl;
  }
}

/*
11110
11010
11001
00001
*/
