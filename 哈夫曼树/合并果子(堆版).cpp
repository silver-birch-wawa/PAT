#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int v[10000]={0};
int length=0;
void print(int v[],int length){
  int i;
  cout<<endl;
  for(i=0;i<length;i++){
    cout<<v[i]<<endl;
  }
}
void in(int v[],int num){
  //cout<<">>>"<<num<<endl;
  if(length==0){
    v[0]=num;
    length++;
    return;
  }
  v[length]=num;
  int l=length;
  length++;
  while(l>0){
    if(v[(l+1)/2-1]>v[l]){
      swap(v[((l+1)/2)-1],v[l]);
      l=(l+1)/2-1;
    }
    else{
      break;
    }
  }
  // cout<<"in:";
  // print(v,length);
}
int del(int v[]){
  if(length<1){
    return 0;
  }
  int res=v[0];
  //v[length-1]=v[0];
  swap(v[length-1],v[0]);
  length--;
  int root=0;
  while(root*2+1<length){
    if(root*2+2<length){
      int left=root*2+1;
      int right=root*2+2;
      if(v[left]>v[right]){
        swap(v[right],v[root]);
        root=right;
      }
      else{
        if(v[left]<v[root]){
          swap(v[left],v[root]);
          root=left;
        }
      }
    }
    else{
      int left=root*2+1;
      if(v[left]<v[root]){
        swap(v[root],v[left]);
        root=left;
      }
      else{
        break;
      }
    }
  }
  // cout<<"del:"<<res;
  // print(v,length);
  return res;
}
bool cmp(int a,int b){
  return a<b;
}
int main(){
  int i,circle=0,t;
  scanf("%d",&circle);
  for(i=0;i<circle;i++){
    scanf("%d",&t);
    // v[i]=t;
    // length++;
    in(v,t);
  }
  //sort(v,v+length,cmp);
  //make_heap(v,v+length,cmp);
  int first,second;
  int ans=0;

  // print(v,length);
  while(length>1){
      // cout<<"length:"<<length<<endl;
      // first=v[0];
      // second=v[1];
      first=del(v);
      second=del(v);
      // cout<<"first:"<<first<<endl;
      // cout<<"second:"<<second<<endl;
      //v.pop_back();

      //cout<<"????"<<endl;
      first+=second;
      ans+=first;
      //v.push_back(first);
      in(v,first);
      //cout<<first<<endl;
      //sort(v+target,v+length);
  }
  cout<<ans;
}

/*
4
4 6 8 14
*/
