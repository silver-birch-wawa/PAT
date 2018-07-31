#include<bits/stdc++.h>
using namespace std;
int N,M;
typedef struct Node{
  int gradeA;
  int gradeC;
  int gradeM;
  int gradeE;
  int rankA;
  int rankC;
  int rankM;
  int rankE;
  int id;
  Node(){

  }
}Node;
int siganl=0;  // 0 1 2 3 对应 A C M E 的排序  4对应 id的排序
bool cmp(Node &a,Node &b){
  switch (siganl) {
    case 0:return a.gradeA>b.gradeA;break;
    case 1:return a.gradeC>b.gradeC;break;
    case 2:return a.gradeM>b.gradeM;break;
    case 3:return a.gradeE>b.gradeE;break;
    case 4:return a.id>b.id;break;
  }
}
int binsearch(Node*stu,int id,int start,int ends){
  int middle=(start+ends)/2;
  if(start>ends){
    return -1;
    // 返回-1说明不存在这个id
  }
  if(stu[middle].id==id){
    return middle;
  }
  else if(stu[middle].id>id){
    binsearch(stu,id,middle+1,ends);
  }
  else{
    binsearch(stu,id,start,middle-1);
  }
}
void search(Node*stu,int id){
  int i,a[4];
  char b[]={'A','C','M','E'};
  id=binsearch(stu,id,0,N-1);
  if(id==-1){
    cout<<"N/A"<<endl;
    return;
  }
  a[0]=stu[id].rankA;
  a[1]=stu[id].rankC;
  a[2]=stu[id].rankM;
  a[3]=stu[id].rankE;
  int rank=stu[id].rankA;
  //cout<<"rank:"<<rank<<endl;
  char types='A';
  // cout<<"????";
  for(i=1;i<4;i++){
    if(rank>a[i]){
      rank=a[i];
      types=b[i];
    }
  }
  cout<<rank<<" "<<types<<endl;
}
int main(int argc, char const *argv[]) {
  int i,j;
  int id,gradeC,gradeM,gradeE;
  scanf("%d %d",&N,&M);
  Node* stu=new Node[N];
  for(i=0;i<N;i++){
    scanf("%d %d %d %d",&id,&gradeC,&gradeM,&gradeE);
    stu[i].id=id;
    stu[i].gradeC=gradeC;
    stu[i].gradeM=gradeM;
    stu[i].gradeE=gradeE;
    stu[i].gradeA=(gradeE+gradeC+gradeM);
  }
  // 对各个单项排序计算
  siganl=0;
  int sum=0;
  // 相同分数的student个数
  sort(stu,stu+N,cmp);
  stu[0].rankA=1;
  for(i=1;i<N;i++){
    if(stu[i].gradeA==stu[i-1].gradeA){
      sum++;
      stu[i].rankA=stu[i-1].rankA;
    }
    else{
      if(sum==0){
        stu[i].rankA=stu[i-1].rankA+1;
      }
      else{
        stu[i].rankA=stu[i-1].rankA+sum+1;
        sum=0;
      }
    }
  }
  siganl=1;
  sort(stu,stu+N,cmp);
  sum=0;
  stu[0].rankC=1;
  for(i=1;i<N;i++){
    if(stu[i].gradeC==stu[i-1].gradeC){
      sum++;
      stu[i].rankC=stu[i-1].rankC;
    }
    else{
      if(sum==0){
        stu[i].rankC=stu[i-1].rankC+1;
      }
      else{
        stu[i].rankC=stu[i-1].rankC+sum+1;
        sum=0;
      }
    }
  }
  siganl=2;
  sort(stu,stu+N,cmp);
  sum=0;
  stu[0].rankM=1;
  for(i=1;i<N;i++){
    if(stu[i].gradeM==stu[i-1].gradeM){
      sum++;
      stu[i].rankM=stu[i-1].rankM;
    }
    else{
      if(sum==0){
        stu[i].rankM=stu[i-1].rankM+1;
      }
      else{
        stu[i].rankM=stu[i-1].rankM+sum+1;
        sum=0;
      }
    }
  }
  siganl=3;
  sort(stu,stu+N,cmp);
  sum=0;
  stu[0].rankE=1;
  for(i=1;i<N;i++){
    if(stu[i].gradeE==stu[i-1].gradeE){
      sum++;
      stu[i].rankE=stu[i-1].rankE;
    }
    else{
      if(sum==0){
        stu[i].rankE=stu[i-1].rankE+1;
      }
      else{
        stu[i].rankE=stu[i-1].rankE+sum+1;
        sum=0;
      }
    }
  }
  siganl=4;
  sort(stu,stu+N,cmp);

  int input;
  for(j=0;j<M;j++){
    scanf("%d",&input);
    if(input>stu[0].id||input<stu[N-1].id){
      cout<<"N/A"<<endl;
    }
    else{
      search(stu,input);
    }
  }
  return 0;
}


/*
5 6
310101 91 85 88
310102 99 95 88
310103 82 87 90
310104 91 93 91
310105 89 91 90
310101
310102
310103
310104
310105
999999
*/
