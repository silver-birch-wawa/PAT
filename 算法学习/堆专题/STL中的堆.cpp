#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(int left, int right)
{
    return left>right;  // С����
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
  // �����󶥶�(Ĭ��)
  make_heap(v,v+length);
  //make_heap(v,v+length,cmp);
  //sort_heap(v,v+length);
  print(v,length);
  // Ԫ�س���(��ʵ���Ƿ�����ĩβ)
  int top=v[0];
  pop_heap(v,v+length);
  // ð��
  length--;


  // Ԫ�����
  v[length]=32;
  length++;
  push_heap(v,v+length);
  // �ָ�����

  // push_heap(v,v+length,cmp);
  print(v,length);
  cout<<endl;
}
