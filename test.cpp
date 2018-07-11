#include <bits/stdc++.h>
using namespace std;
#define N 1000
char input[N];
vector<vector<int>>v;
// 记录回文产生的起点与终点
void record(int start,int end){
  v[start].push_back(end);
}
void show(int start,int end){
  int i;
  cout<<"start from:"<<start<<endl;
  for(i=start;i<=end;i++){
    cout<<input[i]<<">>";
  }
  cout<<endl;
}
void single(char input[],int middle){
  int i,j;
  for(i=1;i<middle+1;i++){
    if(input[middle-i]==input[middle+i]){
      //continue;
    }else{
      if(i>1){
        record(middle-i+1,middle+i-1);
      }
      break;
    }
  }
}
// void double(char input[],int middle1,int middle2){
//
// }
int main(){
  scanf("%s",&input);
  int length=strlen(input);
  int i,j;
  for(i=0;i<length;i++){
    //single(input,i);
    vector<int>vv;
    v.push_back(vv);
  }
  for(i=0;i<length;i++){
    single(input,i);
  }
  for(i=0;i<length;i++){
    if(!v[i].empty()){
      for(j=0;j<v[i].size();j++){
        show(i,v[i][j]);
      }
    }
  }
}

/*
abcdcbaded
*/
