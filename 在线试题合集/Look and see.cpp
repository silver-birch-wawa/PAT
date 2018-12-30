#include<iostream>
#include<vector>
#include<map>
#include<string.h>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
int d,t;
int main(){
  int i;
  scanf("%d %d",&d,&t);
  string s;
  // s+=d;
  s+=to_string(d);
  int times=1;
  // string x;
  while(1){
    string x;
    int i;
    char p=s[0];
    int counts=1;
    for(i=1;i<s.size();i++){
      if(s[i]==s[i-1]){
        counts++;
      }
      else{
        x+=p;
        x+=to_string(counts);
        p=s[i];
        counts=1;
      }
    }
    if(counts!=0){
      x+=p;
      x+=to_string(counts);
    }
    if(times==t-1){
       cout<<x<<endl;
       //printf("%s",x.c_str());
       break;
    }
    times++;
    s=x;
  }
}
