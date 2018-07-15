#include <bits/stdc++.h>
using namespace std;
// 最大值
#define N 100010
// 块的大小
const int sqrtN=316;

vector<int>s;

int block[N]={0};
// 存储块的数据,设为sqrtN会报错....
int table[N]={0};
// 存储对应取值的数据

void findMedian(){
  if(s.empty()){
    cout<<"Invalid"<<endl;
    return;
  }
  int i,j;
  int counts=0;
  int target=0;
  if(s.size()&1){
    // 奇数
    target=(s.size()+1)/2;
  }
  else{
    // 偶数
    target=s.size()/2;
  }
  for(i=0;i<sqrtN;i++){
    counts+=block[i];
    if(counts>=target){
      counts-=block[i];
      // 计算第K个值可能的开始-结束的值
      int bottom=i*sqrtN;
      int hign=(i+1)*sqrtN-1;

      for(j=bottom;j<=hign;j++){
        counts+=table[j];
        if(counts>=target){
          printf("%d\n",j);
          return ;
        }
      }
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
    printf("Invalid\n");
    return;
  }
  int tp=s[s.size()-1];
  s.pop_back();
  // 点值--
  table[tp]--;
  // 块值--
  block[tp/sqrtN]--;
  printf("%d\n",tp);
}
int main(){
  int i,j;
  int times;
  char input[100];

  char Pop[]="Pop";
  char PeekMedian[]="PeekMedian";
  scanf("%d\n",&times);
  // 必须摘去\n要不然会影响到后面的读取

  // 书上的方法只是在该用例输入的时候可以投机取巧，字符串处理最好还是cin.getline(input,N)+string的方式
  for(i=0;i<times;i++){
    scanf("%s",input);
    // 要判断字符串相等需要用string==string,但是用char[]+strcmp更省钱
    if(strcmp(input,Pop)==0){
      Popup();
    }
    else if(strcmp(input,PeekMedian)==0){
      findMedian();
    }
    else{
      int num;
      scanf("%d",&num);
      Push(num);
    }
  }
}
