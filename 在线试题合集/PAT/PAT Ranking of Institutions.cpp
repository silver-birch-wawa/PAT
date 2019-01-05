#include<iostream>
#include<vector>
#include<map>
#include<string.h>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
typedef struct Stu{
  int score;
  int num;
  int rank;
  string name;
}Stu;
bool cmp(Stu a,Stu b){
  if(a.score==b.score){
    if(a.num==b.num){
      if(strcmp(a.name.c_str(),b.name.c_str())>0){
        return false;
      }
      else{
        return true;
      }
    }
    else{
      return a.num<b.num;
    }
  }
  else{
    return a.score>b.score;
  }
}
void convert(string&name){
  int i;
  for(i=0;i<name.size();i++){
    if(name[i]>='A'&&name[i]<='Z'){
      name[i]+='a'-'A';
    }
  }
}
int main(){
  map<string,vector<int>>m;
  int score=0;
  char id[10];
  int i,j,counts=0;
  scanf("%d",&counts);
  for(i=0;i<counts;i++){
    string name;
    cin>>id>>score>>name;
    // scanf("%s %d %s",&id,&score,name.c_str);
    convert(name);
    // cout<<"name:"<<name<<"score:"<<m[name][0]<<endl;
    if(m.count(name)==0){
      vector<int>tws={0,0};
      m[name]=tws;
      //m[name][0]=0;
      //m[name][1]=0;
    }
    if(id[0]=='A'){
        m[name][0]+=score;
        m[name][1]++;
    }
    else if(id[0]=='T'){
        m[name][0]+=(score*1.5);
        m[name][1]++;
    }
    else if(id[0]=='B'){
        m[name][0]+=(score/1.5);
        m[name][1]++;
    }
    // cout<<"name:"<<name<<"score:"<<m[name][0]<<endl;
    // cout<<"-------\n"<<name<<endl;
  }
  cout<<m.size()<<endl;
  vector<Stu>stu;
  for(map<string,vector<int>>::iterator it=m.begin();it!=m.end();it++){
    Stu s;
    s.name=it->first;
    s.score=it->second[0];
    s.num=it->second[1];
    stu.push_back(s);
  }
  sort(stu.begin(),stu.end(),cmp);
  stu[0].rank=1;
  for(i=1;i<stu.size();i++){
    stu[i].rank=((stu[i].score==stu[i-1].score)?stu[i-1].rank:i+1);
  }
  for(i=0;i<stu.size();i++){
    cout<<stu[i].rank<<" "<<stu[i].name<<" "<<stu[i].score<<" "<<stu[i].num<<endl;
  }
}
