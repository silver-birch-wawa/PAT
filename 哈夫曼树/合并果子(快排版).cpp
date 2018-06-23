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
int main(){
  int i,circle=0,t;
  scanf("%d",&circle);
  for(i=0;i<circle;i++){
    scanf("%d",&t);
    v[i]=t;
    length++;
  }
  sort(v,v+length);
  int first,second;
  int ans=0;
  //print(v,length);
  int target=0;
  while(target<length-1){
      first=v[target];
      second=v[target+1];
      //v.pop_back();
      first+=second;
      ans+=first;
      //v.push_back(first);
      v[target+1]=first;
      target++;
      sort(v+target,v+length);
  }
  cout<<ans;
}
