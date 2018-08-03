#include<bits/stdc++.h>
using namespace std;
int N,M,K;
int k[1000]={0};
// 每个人的等待处理时间
int t[1000]={0};
// 存放每个人完成的时间,17:00以后不能 serve(值为0)就返回 Sorry

queue<int>waitingline;
// 等待的队伍,如果溢出的话

/*
第一行 窗口数，最长等待数，顾客数，查询数
各个顾客的业务处理时间
查询的顾客名
*/
typedef struct Windows{
  int next_time;
  // 轮到下一个的时间(秒)
  int length;
  // 队伍长度
  int sumtime;
  // 总计时间，防止总时长超时

  // 排队的人数
  queue<int>q;
  Windows(){
    sumtime=0;
    length=0;
    next_time=0;
  }
}Windows;

bool addin(Windows*win,int target,int id){
  // target 窗口编号 id 队伍元素编号
  if(win[target].sumtime+k[id]>9*60){
    return false;
    // 处理完该业务的截至时间超过银行最晚的营业时间则报错
  }
  win[target].q.push(id);
  win[target].sumtime+=k[id];
  // win[target].length++;
  return true;
}
// 添加时看队伍长度，但是要计算时间
void add(Windows*win,int id){
  // id 第几个顾客
  int length=1000000;
  // 挑选最短的队伍排
  int i,j,target=0;
  for(i=0;i<N;i++){
    if(win[i].q.size()<length){
      length=win[i].q.size();
      target=i;
    }
  }
  // cout<<win[0].q.size()<<"           "<<win[1].q.size()<<endl;
  // 发现最小队列target
  if(length==0){
    // 没人排队则初始化 next_time
    win[target].next_time+=k[id];
    t[id]=k[id];
    // cout<<"id:"<<id<<"  "<<t[id]<<endl;
    if(!addin(win,target,id)){
      // 超时则不插入队列，t[i]为 0 则默认超时
      return;
    }
  }
  else if(length<M){
    // 有人则加入队列
    if(!addin(win,target,id)){
      // 超时则不插入队列，t[i]为 0 则默认超时
      return;
    }
  }
  else{
    // 溢出放入队列
    waitingline.push(id);
  }
}
bool waitaddin(Windows*win,int target,int nextone){
  if(win[target].sumtime+k[nextone]>9*60){
    // cout<<"++++++"<<nextone<<endl;
    return false;
  }
  int out=win[target].q.front();
  t[out]=win[target].next_time;
  win[target].q.pop();

  win[target].q.push(nextone);
  // cout<<"add in"<<k[win[target].q.front()]<<endl;
  win[target].next_time+=k[win[target].q.front()];
  win[target].sumtime+=k[nextone];
  // win[target].length++;
  return true;
}
void waitadd(Windows*win){
  int recent_time=1000000;
  int i,j,target=0;
  int nextone=waitingline.front();
  waitingline.pop();
  // 在一堆可能超时的数据中挑选最合适的
  // win[target].length++;
  for(i=0;i<N;i++){
    if(recent_time>win[i].next_time){
      recent_time=win[i].next_time;
      target=i;
    }
  }
  if(recent_time==1000000){
    //cout<<"???????";
    return;
    // 都超时了
  }
  if(!waitaddin(win,target,nextone)){
    return;
  }
  // t[out]=recent_time+k[nextone];
  // 把该人的完成时间标记
}
void clearqueue(Windows*win){
  int i,j;
  // cout<<"***next_time:"<<win[0].q.size()<<"  "<<win[1].q.size()<<endl;
  for(i=0;i<N;i++){
    int length=win[i].q.size();
    if(length>0){
      int first=win[i].q.front();
      win[i].q.pop();
      t[first]=win[i].next_time;
      for(j=1;j<length;j++){
        int first=win[i].q.front();
        win[i].q.pop();
        win[i].next_time+=k[first];
        t[first]=win[i].next_time;
        //cout<<"q:"<<i<<endl;
        //cout<<"first:"<<first<<endl;
        //cout<<"next_time:"<<t[first]<<endl;
        // win[i].q.pop();
      }
    }
  }
}
void print(){
  int i=0;
  cout<<"----------"<<endl;
  for(i=0;i<K;i++){
    cout<<"time:"<<t[i]<<endl;
  }
}
// 处理时间s->h+m
void times(int t){
  if(t==0){
    cout<<"Sorry"<<endl;
    return;
  }
  int hour=8+t/60;
  int minutes=(t%60);
  cout<<hour<<":";
  printf("%02d\n",minutes);
}
void query(int num){
  times(t[num-1]);
}
int main(){
  int i,j,Q,input;
  scanf("%d %d %d %d",&N,&M,&K,&Q);
  Windows* win=new Windows[N];
  for(i=0;i<K;i++){
    scanf("%d",&input);
    k[i]=input;
    add(win,i);
    // 插入
  }
  // cout<<"***next_time:"<<win[0].next_time<<"  "<<win[1].next_time<<endl;
  // print();
  // 如果黄线之前排满了
  int length=waitingline.size();
  for(i=0;i<length;i++){
    waitadd(win);
  }
  //print();
  // 全部都入队了，对队伍中的最后一批顾客进行清算
  clearqueue(win);
  //print();
  for(i=0;i<Q;i++){
    scanf("%d",&input);
    query(input);
  }
}
