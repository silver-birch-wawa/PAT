#include <bits/stdc++.h>
using namespace std;
#define N 10000
int H[N]={0};
int index(char c){
  int hash=c-'A';
  return hash;
}
int su=10000019;
int main(){
  int i,j;
  char input[N];
  scanf("%d",&input);
  int length=strlen(input);
  H[0]=index(input[0]);
  for(i=1;i<length;i++){
    // 每个输入字符依赖于上一个字符
    H[i]=H[i-1]*26+index(input[i]);
    H[i]%=su;
    // *26避免冲突，%su避免溢出
  }
  cout<<H[length-1]<<endl;
}
