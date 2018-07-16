#include<bits/stdc++.h>
using namespace std;
#define N 1000
#define lowbit(i) ((i)&(-i))
// int maxnum=0;
int n,m;
// n 个数，m个输入
int A[N]={0};
int C[N]={0};
void update(int num,int v){
  int i,j;
  for(i=num;i<=n;i+=lowbit(i)){
    C[i]+=v;
  }
}
int sumup(int num){
  int i,j;
  int length=num;
  int sum=0;
  sum+=A[length];
  length--;
  while(length>0){
    sum+=A[length];
    length-=lowbit(length);
  }
  return sum;
}
int sumBetween(int start,int end){
  return sumup(end)-sumup(start-1);
}
int main(){
  int i,j;
  scanf("%d %d",&n,&m);
  char c;
  int x,y;
  for(i=0;i<m;i++){
    scanf("%c %d %d\n",&c,&x,&y);
    if(c=='C'){
      update(x,y);
    }
    else{
      int sum=sumBetween(x,y);
      cout<<sum<<endl;
    }
  }
}
