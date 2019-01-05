#include<iostream>
using namespace std;
#define N 1000
typedef struct Node{
  int num;
  Node* next;
  Node(){
    num=0;
    next=NULL;
  }
}Node;
void findmiddle(Node*root){
  Node* p=root;
  Node* q=root;
  // p在前面，q在后面
  while((p->next)!=NULL&&((p->next)->next)!=NULL){
    p=((p->next)->next);
    q=q->next;
  }
  cout<<"middle:"<<q->num<<endl;
}
void add(Node*&root,int num){
  if(root==NULL){
    root=new Node();
    root->num=num;
    return;
  }
  add(root->next,num);
}
void print(Node*p){
  while(p!=NULL){
    cout<<p->num<<endl;
    p=p->next;
  }
}
int main(){
  Node*p=NULL;
  add(p,1);
  add(p,2);
  add(p,3);
  add(p,4);
  findmiddle(p);
}
