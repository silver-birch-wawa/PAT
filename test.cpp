#include <bits/stdc++.h>
using namespace std;
#define N 1000
int bags[N]={0};
int goods,volumns;
int value[N]={0};
int weight[N]={0};
bool path[N][N]={false};
int main(){
  int i,j;
  //scanf("%d %d",&goods,&volumns);
  scanf("%d %d",&volumns,&goods);
  int w,v;
  for(i=0;i<goods;i++){
    scanf("%d %d",&w,&v);
    value[i]=v;
    weight[i]=w;
  }
  for(i=0;i<goods;i++){
    for(j=weight[i];j<volumns+1;j++){
        //bags[j]=max(bags[j],bags[j-weight[i]]+value[i]);
        if(bags[j]<bags[j-weight[i]]+value[i]){
          bags[j]=bags[j-weight[i]]+value[i];
          path[i][j]=true;
        }
    }
  }
  int x=goods-1,y=volumns;
  v=bags[volumns];
  while(x>=0&&y>=0&&v>=0){
    if(path[x][y]==true){
      cout<<">>"<<x;
      y-=weight[x];
      v-=value[x];
    }
    else{
      x--;
    }
  }
  cout<<"\nmax value:"<<bags[volumns]<<endl;
}

/*
abcdcbaded
*/
