#include <bits/stdc++.h>
using namespace std;
int circle=0;
#define maxn 10000
bool Root[maxn][maxn]={false};  // 是否被遍历过的标记位
int root[maxn]={0};      // 权值sum的值，为两边的线权值之和，计算总和只要把所有sum加一起然后除2

int Head=0;
void DFS(int begin,int &head,int &len,int &sum){
  int i,j;

  for(i=1;i<circle+1;i++){
    // cout<<"------------"<<begin<<endl;
    if(Root[begin][i]==true&&Root[i][0]==false&&i!=Head){
      Root[i][0]=true;
      Root[begin][i]=false;
      sum+=root[i];
      len++;

      if(root[i]>root[head]){
        head=i;
      }
      DFS(i,head,len,sum);
    }
  }
}
struct res{
  int len;
  string ans;
};

// 不单单要比较第一位，后面的几位也要参与排序
bool cmp(res s1,res s2){
  int i=0;
  for(i=0;i<max(s1.ans.size(),s2.ans.size());i++){
        if(s1.ans[i]!=s2.ans[i]){
           return  s1.ans[i]<s2.ans[i];
        }
  }
  return true;
}
void insert(int point,int num){
  Root[point][num]=true;
}
int main(){
  string s[20000];
  int i,K=0;
  map<string,int>m;
  scanf("%d %d",&circle,&K);

  int input;
  char a[20000],b[20000];

  string str1,str2;

  int signal=1;
  // 因为字典null为0，所以从1开始递增映射
  for(i=0;i<circle;i++){
    scanf("%s %s %d",a,b,&input);
    str1=a;
    if(m[str1]==0){
      m[str1]=signal++;
      s[signal-1]=str1;
    }
    str2=b;

    if(m[str2]==0){
      m[str2]=signal++;
      s[signal-1]=str2;
    }
    root[m[str1]]+=input;
    root[m[str2]]+=input;

    insert(m[str1],m[str2]);
  }

  int head=0,len=0,sum=0;

  vector<res>ss;
  // 存储答案
  for(i=1;i<circle+1;i++){
    head=i;
    len=1;
    sum=root[i];
    Head=i;
    DFS(i,head,len,sum);

    // cout<<s[i]<<endl;
    // cout<<"start:"<<s[i]<<endl;
    // cout<<"head:"<<s[head]<<endl;
    // cout<<"len:"<<len<<endl;
    // cout<<"sum:"<<sum/2<<endl;
    // cout<<endl;

    if(sum>K*2&&len>2){
      res r;
      r.len=len;
      r.ans=s[head];
      ss.push_back(r);
    }
  }
  if(ss.size()==0){
    cout<<0;
    return 0;
  }
  cout<<ss.size()<<endl;

  sort(ss.begin(),ss.end(),cmp);

  for(i=0;i<ss.size();i++){
    cout<<ss[i].ans<<" "<<ss[i].len<<endl;
  }
  // for(i=1;i<circle+1;i++){
  //   cout<<"ans:"<<root[i]<<endl;
  // }
  // print(root);
}
