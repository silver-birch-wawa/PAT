#include <bits/stdc++.h>
using namespace std;
string s[100];
struct Node{
  int sum;
  bool passby;
  int num;
  Node(){
    sum=0;
    num=0;
    passby=false;
  }
};

// void mapiter(map<string,int>m){
//   for(map<string,int>::iterator it;it=m.begin();it!=m.end()){
//     cout<<first<<endl;
//     cout<<second<<endl;
//   }
// }

vector<vector<struct Node> >q;
int circle=0;

void DFS(vector<struct Node>root,int begin,int &head,int &len){
  Node *p;
  //if(begin==circle)
  p=&root[begin];
  if(p->passby==false){
      len++;
      p->passby=true;
      cout<<">>>"<<p->num<<endl;
      if(root[head].sum<root[p->num].sum){
        head=p->num;
      }
      if(p->next!=NULL){
          Node* t=p->next;
          while(t!=NULL){
              len++;
              t->passby=true;
              //cout<<">>>"<<t->num<<endl;
              if(root[head].sum<root[t->num].sum){
                head=t->num;
              }
              t=t->next;
              DFS(root,t->num,head,len);
          }
      }
  }
  // int maxi=root->sum;
  // int head=root->num;
  // q.push_back(root);
  // while(!q.empty()){
  //   // while(gd)
  //   p=q.top();
  //   q.pop();
  //   if(p->num>maxi&&p->passby==false){
  //     head=p->num;
  //     maxi=p->sum;
  //   }
  //   p->passby=true;
  //   p=p->next;
  //   while(p!=NULL&&p!=root&&p->passby==false){
  //     if(p->passby!=true){
  //       q.push_back();
  //       q->passby=true;
  //     }
  //     p=p->next;
  //   }
  // }
}
void insert(Node root[],int point,int num){
  Node *p=root[point].next;
  while(p!=NULL){
    p=p->next;
  }
  p=new Node();
  p->num=num;
}
void print(Node root[]){
  int i=0;
  for(i=0;i<circle;i++){
    cout<<root[i].passby<<endl;
    if(root[i].next==NULL)
    cout<<":::"<<endl;
  }
}
int main(){
  int i,K=0;
  map<string,int>m;
  scanf("%d %d",&circle,&K);

  string str1,str2;
  int input;
  char a[30],b[30];

  int signal=0;

  Node* root=new Node[circle];
  for(i=0;i<circle;i++){
    root[i].num=i;
  }

  for(i=0;i<circle;i++){
    scanf("%s %s %d",a,b,&input);
    str1=a;
    if(m[str1]==0){
      m[str1]=signal++;
      s[signal-1]=str1;
      root[m[str1]].sum+=input;
    }
    str2=b;
    if(m[str2]==0){
      m[str2]=signal++;
      s[signal-1]=str2;
      // 递增型字典
      root[m[str2]].sum+=input;
      // 计算value
    }
    insert(root,m[str1],m[str2]);
  }
  int head=0,len=0;
  for(i=0;i<circle;i++){
    head=i;
    len=0;
    DFS(root,i,head,len);
    cout<<"head:"<<head<<endl;
    cout<<"len:"<<len<<endl;
    print(root);
  }
  //cout<<a;
}
