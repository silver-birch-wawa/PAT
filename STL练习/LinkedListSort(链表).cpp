#include <bits/stdc++.h>
using namespace std;
#define N 100001
typedef struct{
  bool exist;
  int value;
  int address;
  int next;
}Node;
bool cmp(Node a,Node b){
  if(a.exist==false||b.exist==false){
    return a.exist>b.exist;
  }
  else{
    return a.value<b.value;
  }
}
Node node[N];
int main(){
  int i=0;
  for(i=0;i<N;i++){
    node[i].exist=false;
  }
  int circle;
  int address;
  scanf("%d %d",&circle,&address);
  int d;
  for(i=0;i<circle;i++){
    // scanf("%d %d %d",&(p->address),&(p->value),&a);
    scanf("%d",&d);
    scanf("%d %d",&node[d].value,&node[d].next);
    node[d].address=d;
  }
  int count=0;
  int p=address;
  while(p!=-1){
    node[p].exist=true;
    count++;
    p=node[p].next;
  }
  if(count==0){
      printf("0 -1");
  }
  else{
      sort(node,node+N,cmp);
      printf("%d %05d\n",count,node[0].address);
      for(i=0;i<count-1;i++){
        printf("%05d %d %05d\n",node[i].address,node[i].value,node[i+1].address);
      }
      printf("%05d %d %d\n",node[i].address,node[i].value,-1);

  }
}
