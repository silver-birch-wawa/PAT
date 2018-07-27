#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(int left, int right)
{
    return left>right;  // 小顶堆
}
void print(int v[],int length){
  int i;
  cout<<endl;
  for(i=0;i<length;i++){
    cout<<v[i]<<endl;
  }
}
int main(){
  int i,v[]={3,2,1,4,6,5};
  int length=6;
  // 建立大顶堆(默认)
  make_heap(v,v+length);
  //make_heap(v,v+length,cmp);
  //sort_heap(v,v+length);
  print(v,length);
  // 元素出堆(其实就是放在最末尾)
  int top=v[0];
  pop_heap(v,v+length);
  // 冒堆
  length--;


  // 元素入堆
  v[length]=32;
  length++;
  push_heap(v,v+length);
  // 恢复最大堆

  // push_heap(v,v+length,cmp);
  print(v,length);
  cout<<endl;
}
