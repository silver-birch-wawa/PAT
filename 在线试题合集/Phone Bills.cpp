#include<bits/stdc++.h>
using namespace std;
typedef struct customer{
  vector<int>time;
  // +on -off
  string name;
  int namehash;
}customer;
map<string,customer>m;

int costs[24]={0};
int monthnow=0;
// 月份是固定的,单独存放
vector<customer>v;

// 查找hash值是否存在，不存在就返回-1
int searchmap(char name[]){
  int i,j;
  if(m.count(name)==1){
    return 1;
  }
  return -1;
}
// 根据名字hash从小到大排列，方便二叉查找
bool cmp(customer&left,customer&right){
  return left.namehash<right.namehash;
}
// 打印的时候要按照字符大小排序(ascii码小的放前面)
bool cmpstr(customer&left,customer&right){
  // 逐个字符比较,从小到大排序,防止前面一串出现重复
  int leftlen=left.name.size();
  int rightlen=right.name.size();
  int length=min(leftlen,rightlen);
  int i,j;
  for(i=0;i<length;i++){
    if(left.name[i]==right.name[i]){

    }
    else{
      return left.name[i]<right.name[i];
    }
  }
  return leftlen<rightlen;
}
bool cmptime(int a,int b){
  return abs(a)<abs(b);
}
void PrintTime(int time){
  printf("%02d:%02d:%02d ",time/(60*24),(time%(60*24))/60,(time%(60*24))%60);
}
double caculate(int t)
{
    int i,j;
    double sum=0;
    for(i=0;i<t/60;i++)
    {
        sum+=costs[i%24]*60/100.0;
    }
    sum+=costs[i%24]*(t%60)/100.0;
    return sum;
}
double sumup(int start,int ending)
{
    double cost=caculate(ending)-caculate(start);
    printf("$%.2lf\n",cost);
    return cost;
}
void print(vector<customer>&v,int num){
  int i=0,j=1;
  double sum=0;
  // 计算总价
  vector<int>record;
  while(j<v[num].time.size()){
    if(v[num].time[i]>0&&v[num].time[j]<0){
      int start=v[num].time[i];
      int ending=v[num].time[j];
      record.push_back(start);
      record.push_back(ending);
    }
    if(v[num].time[j]>0){
      i++;
      j++;
    }
    else if(v[num].time[j]<0){
      i=j+1;
      j+=2;
    }
  }
  if(record.empty()){
    return;
  }
  printf("%s %02d\n",v[num].name.c_str(),monthnow);
  for(i=0;i<record.size();i+=2){
    PrintTime(record[i]);
    PrintTime(abs(record[i+1]));
    int time=-(record[i]+record[i+1]);
    cout<<time<<" ";
    sum+=sumup(record[i],abs(record[i+1]));
  }
  printf("Total amount: $%.2f\n",sum);
}
int main(){
  int i,j,input;
  for(i=0;i<24;i++){
    scanf("%d",&input);
    costs[i]=input;
  }
  scanf("%d",&input);

  char name[50],sign[20];
  int month,day,hour,minutes,namehash;
  for(j=0;j<input;j++){
    scanf("%s %d:%d:%d:%d %s",name,&month,&day,&hour,&minutes,sign);
    monthnow=month;
    // cout<<"))))))))"<<endl;
    if(!strcmp(sign,"off-line")){
      // 匹配offline成功则返回0
      int target=searchmap(name);
      if(target==-1){
        // 没找到
        customer c;
        c.name=name;
        //c.namehash=hashname(name);
        c.time.push_back((minutes+60*hour+24*60*day)*-1);
        m[name]=c;
        //v.push_back(c);
        // sort(v.begin(),v.end(),cmpstr);
      }
      else{
        m[name].time.push_back((minutes+60*hour+24*60*day)*-1);
        // v[target].time.push_back((minutes+60*hour+24*60*day)*-1);
      }
    }
    else{
      int target=searchmap(name);
      if(target==-1){
        // 没找到
        customer c;
        c.name=name;
        c.time.push_back(minutes+60*hour+24*60*day);
        m[name]=c;
      }
      else{
        m[name].time.push_back(minutes+60*hour+24*60*day);
      }
    }
  }
  for(map<string,customer>::iterator it=m.begin();it!=m.end();it++){
    v.push_back(it->second);
  }
  // 按照题目要求的字符串方式排序
  sort(v.begin(),v.end(),cmpstr);
  for(i=0;i<v.size();i++){
    // 对时间从小到大排序
    sort(v[i].time.begin(),v[i].time.end(),cmptime);
  }
  // 筛选每个customers的bills然后打印
  for(i=0;i<v.size();i++){
    print(v,i);
  }
}
