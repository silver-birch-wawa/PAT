#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<map>
#include <stdlib.h>
#include <time.h>
using namespace std;
#define N 1000
// 使用带头结点的链表，本示例中不考虑重复元素插入删除的情况。
typedef struct Node{
  int num;
  // 每层的首元素对应的num用于计算行的长度，其他层用于存放数据
  Node*next;
  Node*underline;
  Node(){
    next=NULL;
    num=0;
    underline=NULL;
  }
}Node;
// 按照从小到大插入一行。确定插入位置需要上层索引指引。
// 刚好命中上层元素(m<num<n)，
// 沿着m从上到下逐个收缩（每次需要两个指针一前一后这样好回退）
Node* addline(vector<Node*>&v,int line,int num){
  int i=0;
  v[line]->num++;
  // 该行的长度++
  Node*t=new Node();
  t->num=num;

  int linenow=v.size()-1;
  // 当前所在行

  // 初始化两个delete指针
  Node*p=v[linenow];
  Node*q=p->next;
  // 自顶向下到对应 line的上一层节点
  for(;linenow>line;linenow--){
      while(q!=NULL){
        if(q->num>num){
          break;
        }
        q=q->next;
        p=p->next;
      }
      p=p->underline;
      q=p->next;
  }
    // line层不需要下沉(p=p->underline)
  while(q!=NULL){
    if(q->num>num){
        break;
      }
      q=q->next;
      p=p->next;
  }
    // 将点插入p,q两个指针之中
    t->next=q;
    p->next=t;
    return t;
}
// 添加插入的元素到最底层，然后再从下往上逐层按概率添加。
void add(vector<Node*>&v,int num){
  // topline指向上一层插入的num节点，nextline指向下一层插入的num节点，方便上下连接。
  Node* topline;
  Node* underline;
  // 最底层必加，但是最底层不是索引不需要随机数判断。
  underline=addline(v,0,num);
  int height=1;
  // 标记插入的行数

  // srand必须放在函数外面，最好放在main函数里面。
  while(rand()%2==1){
    if(height<v.size()){
      topline=addline(v,height,num);
      topline->underline=underline;
      underline=topline;
    }
    else{
      // 超过表长,添加头节点
      Node* t=new Node();
      t->underline=v[v.size()-1];
      v.push_back(t);
      // 添加元素
      Node *node=addline(v,height,num);
      topline=node;
      topline->underline=underline;
      underline=topline;
    }
    height++;
  }
}
// 依层打印
void print(vector<Node*>v){
  int i;
  cout<<"v has level: "<<v.size()-1<<endl;
  for(i=0;i<v.size();i++){
    cout<<"No."<<i<<" level:  ";
    Node*p=v[i]->next;
    while(p!=NULL){
      cout<<p->num<<" ";
      p=p->next;
    }
    cout<<endl;
  }
}
// 删除用它的underline指针
void del(vector<Node*>&v,int num){
  int i,j;
  int linenow=v.size()-1;
  Node*p;
  Node*q;
  while(linenow>=0){
    p=v[linenow];
    q=p->next;

    while(q!=NULL){
      if(q->num==num){
        // 元素数小于等于2了整行删除
        if(v[linenow]->num<=2){
          p=p->underline;
          q=p->next;
          int sz=v.size();
          // v.size()在pop的时候会变化，所以要先缓存着
          for(i=0;i<sz-linenow;i++)
          {
              // 如果上面有小于1的顶，那么也得一块删除。要不然只删除中间行的操作会很繁琐。
              v.pop_back();
          }
          break;
        }
        // 正常删除
        p->next=q->next;
        free(q);

        // 如果不是最底层不需要下沉
        if(linenow>0){
          p=p->underline;
          q=p->next;
        }
        break;
      }
      else if(q->num>num){
        p=p->underline;
        q=p->next;
        break;
      }
      else{
        p=p->next;
        q=q->next;
      }
    }
    linenow--;
  }
}
int main(){
  int i,j;
  vector<Node*>v;
  Node *node=new Node();
  v.push_back(node);
  srand((unsigned)time(NULL));
  add(v,4);
  add(v,2);
  add(v,3);
  add(v,1);
  add(v,6);
  add(v,5);
  print(v);
  // 输入要删除的元素
  cin>>i;
  del(v,i);
  print(v);
}
