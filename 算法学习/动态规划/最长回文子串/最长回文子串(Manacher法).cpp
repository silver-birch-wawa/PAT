#include <bits/stdc++.h>
using namespace std;
#define N 1000
char input[N],a[N];
vector<vector<int>>v;
int length;
// 记录字符长度

int max_length=0;
//记录最大长度

// 记录回文产生的起点与终点
void record(int start,int end){
  if(max_length<(end-start+1)/2){
    max_length=(end-start+1)/2;
  }
  v[start].push_back(end);
}
void show(int start,int end){
  int i;
  cout<<"\nstart from:"<<start<<"\nend at:"<<end<<endl;
  for(i=start;i<=end;i++){
    if(input[i]!='#')cout<<input[i]<<">>";
  }
  cout<<endl;
}
void Single(char input[],int middle){
  int i,j;
  // 要不往左middle次迭代，要不往右length-1-middle次迭代
  for(i=1;i<=min(middle,length-1-middle);i++){
    if(input[middle-i]==input[middle+i]){

    }else{
      break;
    }
  }
  if(i>2){
    // 考虑到 d#b#a#b#x(i>=4) x#b#b#y(i>=3)，所以i>2
    record(middle-i+1,middle+i-1);
  }
}
int main(){
  int i,j;
  scanf("%s",&a);
  input[0]='#';
  for(i=0;i<strlen(a);i++){
    input[2*i+1]=a[i];
    input[2*i+2]='#';
  }
  input[strlen(a)*2+1]='\0';
  length=strlen(input);

  for(i=0;i<length;i++){
    vector<int>vv;
    v.push_back(vv);
  }
  for(i=0;i<length;i++){
    //if(input[i]!='#')
    // middle遇到#也要算进去，这样可以少处理偶数的情况
    Single(input,i);
  }
  for(i=0;i<length;i++){
    if(!v[i].empty()){
      for(j=0;j<v[i].size();j++){
        show(i,v[i][j]);
      }
    }
  }
  cout<<"\nmax_length:"<<max_length<<endl;
}

/*
abcdcbadedab

abcdcbadedababbccbbavenne

abbccbbavenne
*/
