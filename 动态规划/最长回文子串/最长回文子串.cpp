#include <bits/stdc++.h>
using namespace std;
#define N 1000
char input[N];
vector<vector<int>>v;
int length;
// 记录字符长度

int max_length=0;
//记录最大长度

// 记录回文产生的起点与终点
void record(int start,int end){
  if(max_length<end-start+1){
    max_length=end-start+1;
  }
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
void Single(char input[],int middle){
  int i,j;
  // 要不往左middle次迭代，要不往右length-1-middle次迭代
  for(i=1;i<=min(middle,length-1-middle);i++){
    if(input[middle-i]==input[middle+i]){
    }else{
      // 如果串头在input[0]则会record失败，所以or循环后统一判断
      // if(i>1){
      //   record(middle-i+1,middle+i-1);
      // }
      break;
    }
  }
  if(i>1){
    record(middle-i+1,middle+i-1);
  }
}
void Double(char input[],int middle1,int middle2){
  int i,j;
  // 因为input[middle1]==input[middle2]才有后面的操作，所以是从0开始不是1
  for(i=0;i<=min(middle1,length-1-middle2);i++){
    if(input[middle1-i]==input[middle2+i]){
    }
    else{
      break;
    }
  }
  if(i>0){
    record(middle1-i+1,middle2+i-1);
  }
}
int main(){
  scanf("%s",&input);
  length=strlen(input);
  int i,j;
  for(i=0;i<length;i++){
    vector<int>vv;
    v.push_back(vv);
  }
  for(i=0;i<length;i++){
    Single(input,i);
  }
  for(i=0;i<length-1;i++){
    Double(input,i,i+1);
  }
  for(i=0;i<length;i++){
    if(!v[i].empty()){
      for(j=0;j<v[i].size();j++){
        show(i,v[i][j]);
      }
    }
  }
  cout<<"max_length:"<<max_length<<endl;
}

/*
abcdcbadedab

abcdcbadedababbccbbavenne

abbccbbavenne
*/
