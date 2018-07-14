#include <bits/stdc++.h>
using namespace std;
#define N 100010
// 块的大小
const int sqrtN=316;

vector<int>s;
vector<int>res;

int block[N]={0};
// 存储块的数据
int table[N]={0};
// 存储对应取值的数据

//所有块中的最大值（这里取个比较大的数作为标准）
int maxnum=100010;

/*
// 本例使用固定block，所以不需要这些了
int getN(int num){
  float m=float(num);
  return int(sqrt(m)+1);
}
int getmax(){
  int length=s.size();
  int i,j;
  int maxnum=0;
  for(i=0;i<length;i++){
    if(maxnum<s[i]){
      maxnum=s[i];
      // 最大值
    }
    table[s[i]]++;
  }
  return maxnum;
}
*/
int findMedian(){
  if(s.empty()){
    res.push_back(-1);
    return -1;
  }
  int i,j;
  int counts=0;
  int target=0;
  if(s.size()&1){
    target=(s.size()+1)/2;
  }
  else{
    target=s.size()/2;
  }
  for(i=0;i<sqrtN;i++){
    counts+=block[i];
    if(counts>=target){
      counts-=block[i];
      //cout<<"target:"<<target<<endl;
      //cout<<"counts:"<<counts<<endl;
      int bottom=i*sqrtN;
      int hign=(i+1)*sqrtN-1;
      for(j=bottom;j<=hign;j++){
        counts+=table[j];
        if(counts>=target){
          res.push_back(j);
          return j;
        }
      }
      //break;
    }
  }
}
void Push(int num){
  table[num]++;
  block[num/sqrtN]++;
  s.push_back(num);
}
void Popup(){
  if(s.empty()){
    res.push_back(-1);
    return;
  }
  int tp=s[s.size()-1];
  s.pop_back();
  table[tp]--;
  block[tp/sqrtN]--;
  res.push_back(tp);
}
int main(){
  int i,j;
  int times;
  // 块的大小/数量
  char input[100];

  char Pop[]="Pop";
  char PeekMedian[]="PeekMedian";
  //cout<<getN(9);
  scanf("%d\n",&times);
  //fflush(stdin);
  for(i=0;i<times;i++){
    // scanf("%s",s);
    // scanf无法处理空格造成的隔断。
    cin.getline(input,N);

    // 要判断字符串相等需要用string==string
    if(strcmp(input,Pop)==0){
      // pop
      //cout<<"find pop"<<endl;
      Popup();
    }
    else if(strcmp(input,PeekMedian)==0){
      //cout<<"find PeekMedian"<<endl;
      int peek=findMedian();
      //cout<<"peak:"<<peek<<endl;
    }
    else{
      char *p=input;
      p=p+4;
      // 处理push
      int num=atoi(p);
      //cout<<num<<endl;
      Push(num);
    }
  }
  for(i=0;i<res.size();i++){
    if(res[i]==-1)cout<<"Invalid"<<endl;
    else{cout<<res[i]<<endl;}
  }
}

/*
3
push 3
PeekMedian
Pop
*/
