#include <bits/stdc++.h>
using namespace std;
#define N 1000
int Next[N]={0};
// 当第n位不匹配时怎么跳。
void getnext(char pattern[]){
  int i=0,j=0,k=0;
  // 事先约定好的两位
  Next[0]=-1;
  // 第一位不跳，-1位不存在匹配的情况。
  Next[1]=-1;
  // 第二位不匹配，但第一位匹配，移动一位。比如ab与ac不匹配，肯定将i移动到b后面。

  for(i=2;i<strlen(pattern);i++){
    // 从pattern[2]开始不匹配时
    Next[i]=-1;
    // 从长到短
    for(j=i-2;j>=0;j--){
      // j的结束位置从[0,i-2]，开始位置默认0的贴前字符串
      for(k=0;k<=j;k++){
        // [0,k]的贴前字符串与[i-1-j+k,i-1]的贴后字符串。
        //cout<<"i:"<<i<<"  k:"<<k<<"  "<<pattern[k]<<"  j:"<<j<<"  "<<pattern[i-1-j+k]<<endl;
        if(pattern[k]==pattern[i-1-j+k]){
          // 继续
        }
        else{
          // 匹配失败，中断退出
          break;
        }
      }
      if(k==j+1){
        // k一直匹配到最后
        Next[i]=j+1;
        // 最长的匹配子串长度(0-j),所以长度是j+1
        break;
        // 后面不需要遍历了，因为是从高到低，所以它已经是最长的了。
      }
    }
  }
}
void show(char text[],int start,int end){
  int i;
  for(i=start;i<=end;i++){
    cout<<text[i];
  }
}
void kmp(char text[],char pattern[]){
  int i=0,j=0;
  int t=strlen(text);
  int p=strlen(pattern);
  bool pass=false;
  while(i<t){
    // 只要看text的指针有没有越界即可，反正pattern的指针j越界就会跳出循环匹配成功
    //cout<<i<<"   "<<j<<"  "<<Next[j]<<endl;
    if(text[i]==pattern[j]){
      i++;
      j++;
    }
    else{
      if(Next[j]==-1&&j==0){
        // 如果没有找到串内重复的串，只需要将pattern的指针指向开头就好。
        // ab与ac如果把j=0，i不动的话，会陷入死循环。
        i++;
      }
      else if(Next[j]==-1){
        j=0;
      }
      else{
        // 如果匹配失败，将j指针指向Next[j]对应的地址。
        j=(Next[j]);
      }
    }
    if(j==strlen(pattern)){
      pass=true;
      cout<<"\nmatch: ["<<i-strlen(pattern)<<","<<i-1<<"]"<<endl;
      show(text,i-strlen(pattern),i-1);
    }
  }
  if(!pass)cout<<"\nNo matching"<<endl;
}
int main(){
  int i,j;
  char text[N]="abababaabcabaabc";
  char pattern[N]="abaabc";
  getnext(pattern);
  cout<<"next[]:  ";
  for(i=0;i<strlen(pattern);i++){
    cout<<Next[i]<<">>";
  }
  kmp(text,pattern);
}
