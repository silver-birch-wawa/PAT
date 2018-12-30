#include<iostream>
using namespace std;
int counts=0;
typedef struct Node{
  int num;
  Node* next;
  Node(){
    next=NULL;
  }
}Node;
void insert(Node*&root,int num){
  counts++;
  if(root->next==NULL){
    root->next=new Node();
    (root->next)->num=num;
    (root->next)->next=NULL;
  }
  else{
    Node* t=new Node();
    t->num=num;
    t->next=(root->next);
    (root->next)=t;
  }
}
void print(Node *root){
  Node *t=root;
  while(t->next!=NULL){
    t=t->next;
    cout<<"*"<<t->num;
  }
  cout<<endl;
}
void rev(Node*&root){
  // 1.为空
  if((root->next)==NULL)
  {
    return;
  }
  // 2. 只有一个
  else if(counts==1)
  {
    // cout<<"*"<<(root->next)->num<<endl;
  }
  // 3. >=两个
  else{
    Node* p1;
    Node* p2;
    Node* p3;
    p1=root;
    p2=(root->next);
    p3=(p2->next);

    // 对头结点处进行单独的预处理
    root->next=NULL;
    p2->next=NULL;
    p1=p2;
    p2=p3;
    p3=p3->next;

    while(p3!=NULL){
      p2->next=p1;

      p1=p2;
      p2=p3;
      p3=p3->next;
    }
    // 最后一个节点的处理也要补上
    p2->next=p1;
    // 补上头结点的处理
    root->next=p2;
  }
}
int main(){
  int i=0,j=0;
  Node *root=new Node();
  insert(root,3);
  insert(root,2);
  insert(root,1);
  print(root);
  rev(root);
  print(root);
}
