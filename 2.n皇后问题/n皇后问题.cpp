#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
void exchange(int input[],int p,int q){
  int temp=input[p];
  input[p]=input[q];
  input[q]=temp;
}
int p(int input[],int check[],int start,int end){
  int i=0,j=0;
  if(start==end){
      // 测试是否是在y=-x+b上
      for(i=0;i<end;i++){
         check[i]=i+1+input[i];
      }
      sort(check,check+end);
      int num=check[0];
      for(j=1;j<end;j++){
          if(num==check[j]){
            return 0;
          }
          else{
            num=check[j];
          }
      }
      // 测试是否是在y=x+b上
      for(i=0;i<end;i++){
         check[i]=i+1-input[i];
      }
      sort(check,check+end);
      num=check[0];
      for(j=1;j<end;j++){
          if(num==check[j]){
            return 0;
          }
          else{
            num=check[j];
          }
      }
      // 测试通过打印结果
      for(i=0;i<end;i++){
          printf("%d",input[i]);
      }
      printf("\n");
  }
  for(int i=start;i<end;i++){
     exchange(input,start,i);
     p(input,check,start+1,end);
     exchange(input,start,i);
  }
}
int main(){
  int length,i,j;
  scanf("%d",&length);
  int input[10];
  int check[10];
  for(i=0;i<length;i++){
    input[i]=i+1;
    check[i]=i+1;
  }
  p(input,check,0,length);
}
