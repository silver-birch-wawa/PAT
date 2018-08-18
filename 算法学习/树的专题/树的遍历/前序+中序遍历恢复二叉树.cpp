#include<iostream>
#include<cstdio>
using namespace std;
#define N 1000
int counts=0;
int preorder[N]={0};
int inorder[N]={0};
typedef struct Node{
  int num;
  Node*left;
  Node*right;
  Node(){
    left=NULL;
    right=NULL;
    num=0;
  }
}Node;
// 如果有题目需求可以改成map查找
int search(int target){
  int i;
  for(i=0;i<counts;i++){
    if(inorder[i]==target){
      return i;
    }
  }
}
// LL,LR,RL,RR是在preorder中的标记位。 middle是上一轮的newmiddle在inorder中的标记位。
void built(Node*&root,int LL,int LR,int middle,int RL,int RR){
  cout<<"\nmiddle:"<<middle<<endl;
  cout<<"LL:"<<LL<<"  LR:"<<LR<<endl;
  cout<<"Rl:"<<RL<<"  RR:"<<RR<<endl;
  if(LL==LR){
    // cout<<"end in:"<<LL<<endl;
    Node*node=new Node();
    node->num=preorder[LL];
    root->left=node;
    // return;
    // 不要立即返回，要不然后面的==的情况会被忽略
  }
  if(RL==RR){
    // cout<<"end in:"<<RR<<endl;
    Node*node=new Node();
    node->num=preorder[RL];
    root->right=node;
    // return;
  }
  if(LL<LR){
    Node*node=new Node();
    node->num=preorder[LL];
    root->left=node;
    int newmiddle=search(preorder[LL]);
    int rlength=(middle-newmiddle-1);
    int llength=(LR-LL)-rlength;
    built(root->left,LL+1,LL+llength,newmiddle,LR-(rlength-1),LR);
  }
  if(RL<RR){
    Node*node=new Node();
    node->num=preorder[RL];
    root->right=node;
    int newmiddle=search(preorder[RL]);
    int llength=(newmiddle-middle-1);
    int rlength=(RR-RL)-llength;
    built(root->right,RL+1,RL+llength,newmiddle,RR-(rlength-1),RR);
  }
}
void print(Node*root){
  if(root==NULL){
    return ;
  }
  print(root->left);
  print(root->right);
  cout<<root->num<<"->";
}
int main(){
  int i,j;
  cin>>counts;
  for(i=0;i<counts;i++){
    cin>>preorder[i];
  }
  for(i=0;i<counts;i++){
    cin>>inorder[i];
  }
  Node*root=NULL;
  Node*node=new Node();
  node->num=preorder[0];
  root=node;
  int middle=search(preorder[0]);
  //
  built(root,1,middle,middle,middle+1,counts-1);
  print(root);
}

/*
9
1 2 3 4 5 6 8 9 7
3 2 4 1 8 6 9 5 7
*/
