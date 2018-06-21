/*
test:

4 2
1 4
2 3

7 5
1 2
2 3
1 3
1 4
5 6
*/
#include<vector>
#include <iostream>
using namespace std;
#define N 100001
int father[N],sum,relations;

int findFather(int x){
  int b=x;
  while (x!=father[x]) {
    x=father[x];
  }
  while(b!=father[b]){
    int t=father[b];
    father[b]=x;
    b=t;
  }
  return x;
}
void Union(int a,int b){
  int faA=findFather(a);
  int faB=findFather(b);
  father[faA]=faB;
}
bool init[N]={false};

int main(){
  int i,j,a,b;
  vector<int>v;
  scanf("%d %d",&sum,&relations);
  for(i=1;i<sum+1;i++){
    father[i]=i;
  }
  for(i=0;i<relations;i++){
    scanf("%d %d",&a,&b);
    // father[max(a,b)]=min(a,b);   //如果max一样的话会相互覆盖输出错误。
    Union(a,b);
  }

  for(i=1;i<sum+1;i++){
      int res=findFather(i);
      init[res]=true;
  }
  int cal=0;
  for(i=1;i<sum+1;i++){
    if(init[i]==true){
      cal++;
    }
  }
  printf("%d",cal);
}
