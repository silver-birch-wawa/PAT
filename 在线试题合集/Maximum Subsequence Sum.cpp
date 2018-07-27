#include<bits/stdc++.h>
using namespace std;
#define N 100000
int num[N]={0};
int Sum[N]={0};

int counts=0;
int sumup(int start,int ending){
  int i,j;
  int sum=0;
  if(start!=0){
    return Sum[ending]-Sum[start-1];
  }
  else{
    return Sum[ending];
  }
}
int start,ending;
vector<int>v;
int sumij=N;
int maxsum(){
  int i,j,sum=-N;
  for(i=0;i<counts;i++){
    for(j=0;j<=i;j++){
      int res=sumup(j,i);
      if(res>sum){
        sum=res;
        start=j;
        ending=i;
      }
    }
  }
  return sum;
}
bool check(int start,int ending){
  int i,j;
  for(i=start;i<=ending;i++){
    if(num[i]>=0){
      // num非负数，>=0而不是>0
      return false;
    }
  }
  return true;
}
int main(){
  scanf("%d",&counts);
  int i,j;
  for(i=0;i<counts;i++){
    scanf("%d",&j);
    num[i]=j;
    if(i!=0){
      Sum[i]=Sum[i-1]+num[i];
    }
    else{
      Sum[i]=num[i];
    }
  }
  int sum=maxsum();
  if(check(start,ending)){
    cout<<0<<" "<<num[0]<<" "<<num[counts-1]<<endl;
  }else{
    cout<<sum<<" "<<num[start]<<" "<<num[ending];
  }
}

/*
6
-1 -2 -3 0 -3 -2
*/
