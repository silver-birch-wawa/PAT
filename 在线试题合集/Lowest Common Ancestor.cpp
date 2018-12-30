#include<iostream>
#include<map>
#include<vector>
using namespace std;
map<int,bool>exist;
typedef struct Node{
  int num;
  // vector<int>fathers;
  Node*left,*right;
  Node(){
    left=NULL;
    right=NULL;
  }
}Node;
vector<vector<int>>f;
void insert(Node*&root,int p,vector<int>&vv){
  if(root==NULL){
    int i;
    root=new Node();
    root->num=p;
    // cout<<"*******";
    for(i=0;i<vv.size();i++){
      f[p].push_back(vv[i]);
      // cout<<"m:"<<vv[i]<<endl;
    }
    // f[p].push_back(p);
    // cout<<"^^^^^^^^^";
    return;
  }
  else if(root!=NULL){
    int father=root->num;
    vv.push_back(father);
    if(root->num<p){
      insert(root->left,p,vv);
    }
    else{
      insert(root->right,p,vv);
    }
  }
}
int findfather(int minnum,int maxnum){
  int i,j;
  int l1=f[minnum].size();
  int l2=f[maxnum].size();
  for(i=0;i<f[minnum].size();i++){
    if(f[minnum][l1-1-i]==maxnum){
      return maxnum;
    }
    for(j=0;j<f[maxnum].size();i++){
      if(f[maxnum][l2-1-j]==minnum){
        return minnum;
      }
      //cout<<"mm:"<<f[minnum][l1-1-i]<<"  "<<f[maxnum][l2-1-j]<<endl;
      if(f[minnum][l1-1-i]==f[maxnum][l2-1-j]){
        return f[minnum][l1-1-i];
      }
    }
  }
  return -1;
}
int main(){
  int i,j,input;
  int M,N;
  Node*root=NULL;
  vector<int>vv;
  scanf("%d %d",&M,&N);
  for(i=0;i<N+1;i++){
    f.push_back(vv);
  }
  for(i=0;i<N;i++){
    scanf("%d",&input);
    exist[input]=true;
    vv.clear();
    insert(root,input,vv);
  }
  // vector<int>vv;

  int input1,input2;
  for(i=0;i<M;i++){
    scanf("%d %d",&input1,&input2);
    // ERROR: 0 is not found.
    if(exist.count(input1)==0&&exist.count(input2)==0){
      cout<<"ERROR: "<<input1<<" and "<<input2<<" are not found."<<endl;
    }
    else if(exist.count(input1)==0){
      cout<<"ERROR: "<<input1<<" is not found."<<endl;
    }
    else if(exist.count(input2)==0){
      cout<<"ERROR: "<<input2<<" is not found."<<endl;
    }
    else{
      int minnum=min(input1,input2);
      int maxnum=max(input1,input2);
      // LCA of 2 and 5 is 3.
      int res=findfather(minnum,maxnum);
      if(res==minnum||res==maxnum){
        cout<<maxnum<<" is an ancestor of "<<minnum<<"."<<endl;
      }
      else{
        cout<<"LCA of "<<minnum<<" and "<<maxnum<<" is "<<res<<"."<<endl;
      }
    }
    // 8 is an ancestor of 7.
  }
}
