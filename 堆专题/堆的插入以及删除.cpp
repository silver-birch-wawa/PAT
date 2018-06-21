#include <iostream>
#include<cstdio>
using namespace std;
struct Heap{
  int heap[1000];
  int length;
  Heap(){
    length=0;
    //heap[100]={0};
  }
};
void print(struct Heap heap){
  int i=0;
  for(i=0;i<heap.length;i++){
    //printf("%d\n",heap.heap[i]);
    cout<<heap.heap[i]<<endl;
  }
}
// ��ֻ��Ҫ����a[i]>=a[i*2+1]&&a[i]>=a[i*2+2]
void build_heap(struct Heap &heap,int num){
  // ���� & ���޷��޸�
  int foot,next;
  heap.heap[heap.length++]=num;
  foot=heap.length-1;
  //cout<<"----------------";
  while(foot>0){
    next=(foot+1)/2-1;
    // �󶥶�
    if(heap.heap[next]<heap.heap[foot]){
      swap(heap.heap[next],heap.heap[foot]);
    }
    else{
      break;
    }
    foot=next;
  }
};
// ɾ��������ժ������Ԫ�أ�Ȼ����a[length-1]�滻���ٱ߱Ƚϱ��³���
int del(struct Heap & heap){
  if(heap.length==0){
    return -1;
  }
  int pop=heap.heap[0];
  swap(heap.heap[0],heap.heap[heap.length-1]);
  heap.length--;

  if(heap.length==1){
      return pop;
  }
  else{
      int next=0;
      int root=0;
      // ��root���������ڶ���Ľڵ㣬��Ϊ����ȫ������������ֻ��������������ֻ�����������������
      while(root<=(heap.length)/2-1){
        if(root*2+2<heap.length){
            if(heap.heap[root*2+1]>heap.heap[root*2+2]){
              next=root*2+1;
              if(next<heap.length){
                // ����������Ϊnull����������Ҫ������滻
                swap(heap.heap[next],heap.heap[root]);
              }
            }
            else{
              next=root*2+2;
              if(next<heap.length){
                // ����������Ϊnull����������Ҫ������滻
                swap(heap.heap[next],heap.heap[root]);
              }
            }
        }
        else if(heap.heap[root]>heap.heap[root*2+1]){
            next=root*2+1;
            swap(heap.heap[next],heap.heap[root]);
        }
        root=next;
      }
  }
  return pop;
}

int main(){
  int length=5;
  //int length=2;
  int i;
  struct Heap heap;
  int a[]={4,8,6,5,9};
  //int a[]={5,4};
  for(i=0;i<length;i++){
    build_heap(heap,a[i]);
  }
  //cout<<heap.length<<endl;
  cout<<"before sort:\n"<<endl;
  print(heap);
  cout<<"\ndel: "<<del(heap)<<endl;
  cout<<"\nafter del: \n"<<endl;
  print(heap);
}
