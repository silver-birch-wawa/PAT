#include<bits/stdc++.h>
using namespace std;
#define N 10000
struct Node{
  int e;
  double c;
  struct Node* next;
  Node(){
    e=-1;
    c=-1;
    next=NULL;
  };
};
struct Node* node=NULL;
void add(int e,double c){
  // cout<<"e:"<<e<<"c:"<<c<<endl;
  if(node==NULL){
    // 当串上没有元素的时候
    struct Node* n=new Node();
    n->e=e;
    n->c=c;
    node=n;
    return;
  }
  Node *root=node;
  Node *pre=NULL;
  while(1){
    if(root==NULL){
      // 遍历到串尾则创建新node
      struct Node* n=new Node();
      n->e=e;
      n->c=c;
      pre->next=n;
      break;
    }
    else if(root->e<e){
      // 发现在中间则插入中间
      struct Node* n=new Node();
      n->e=e;
      n->c=c;
      n->next=root;
      pre->next=n;
      break;
    }
    else if(root->e==e){
      // 发现相等则在原有基础上+=
      root->c+=c;
      break;
    }
    else{
      // 要不然就接着next下去
      pre=root;
      root=root->next;
    }
  }
}
/*

2 1 2.4 0 3.2
2 2 1.5 1 0.5

3 3 3.6 2 6.0 1 1.6

1+2=3 2.4*1.5=3.6 (3,3.6)
1+1=2 2.4*0.5=1.2 (2,1.2)
0+2=2 1.5*3.2=4.8 (2,4.8)
0+1=1 3.2*0.5=1.6 (1,1.6)

3 (3 3.6) (2 1.2+4.8) (1 1.6)

*/
int exponent1[N]={0};
double coefficient1[N]={0};

int exponent2[N]={0};
double coefficient2[N]={0};

int main(){
  double c;
  int e,i,j,counts;
  int length1=0,length2=0;
  scanf("%d",&counts);
  for(i=0;i<counts;i++){
    scanf("%d %lf",&e,&c);
    length1++;
    exponent1[i]=e;
    coefficient1[i]=c;
  }
  scanf("%d",&counts);
  // cout<<"counts:"<<counts<<endl;
  for(i=0;i<counts;i++){
    scanf("%d %lf",&e,&c);
    // cout<<"e:"<<e<<"c:"<<c<<endl;
    length2++;
    exponent2[i]=e;
    coefficient2[i]=c;
  }
  for(i=0;i<length1;i++){
    for(j=0;j<length2;j++){
      add(exponent1[i]+exponent2[j],coefficient1[i]*coefficient2[j]);
    }
  }
  int length=0;
  struct Node *root=node;
  vector<double>v;
  while(1){
    if(root==NULL){
      break;
    }
    else{
      v.push_back(root->e);
      v.push_back(root->c);
      root=root->next;
      length++;
    }
  }
  if(length==0){
    cout<<0<<endl;
    return 0;
  }
  cout<<length;
  for(i=0;i<v.size();i+=2){
    cout<<" "<<v[i];
    printf(" %.1f",v[i+1]);
    // cout<<exponent1[i]<<endl;
    // cout<<exponent2[i]<<endl;
  }
}
/*
1 0 3
1 0 2
*/
