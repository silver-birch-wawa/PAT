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
// 堆只需要满足a[i]>=a[i*2+1]&&a[i]>=a[i*2+2]
void build_heap(struct Heap &heap,int num){
  // 不加 & 会无法修改
  int foot,next;
  heap.heap[heap.length++]=num;
  foot=heap.length-1;
  //cout<<"----------------";
  while(foot>0){
    next=(foot+1)/2-1;
    // 大顶堆
    if(heap.heap[next]<heap.heap[foot]){
      swap(heap.heap[next],heap.heap[foot]);
    }
    else{
      break;
    }
    foot=next;
  }
};
// 跟del很像，只是没有length--而已,因为是大顶堆，所以取下来放末尾的话就是从小到大排序。
void heap_sort(struct Heap & heap){
    int length=heap.length;
// 让root从顶点向倒数第二层节点遍历，因为是完全二叉树，所以只有左右完整还有只有左子树两种情况。因为是大顶堆，
// 所以取第一个肯定是最大的，放置在a[]末尾，然后在root向下递归的时候选出第二大的数并保持最大堆。
  while(heap.length>=2){

    int next=0;
    int root=0;
    swap(heap.heap[0],heap.heap[heap.length-1]);

    heap.length--;

    while(root<=(heap.length)/2-1){
      if(root*2+2<heap.length){
          if(heap.heap[root*2+1]>heap.heap[root*2+2]){
            next=root*2+1;
            if(next<heap.length){
              // 右子树可能为null！！！！需要检查再替换
              swap(heap.heap[next],heap.heap[root]);
            }
          }
          else{
            next=root*2+2;
            if(next<heap.length){
              // 右子树可能为null！！！！需要检查再替换
              swap(heap.heap[next],heap.heap[root]);
            }
          }
      }
      else if(heap.heap[root]<heap.heap[root*2+1]){
          next=root*2+1;
          swap(heap.heap[next],heap.heap[root]);
          // cout<<">>>>"<<heap.heap[next]<<":"<<heap.heap[root]<<endl;
      }
      else{
        break;   // 如果满足a[i]>=a[i*2+1]说明下沉任务已完成。
      }
      root=next;
    }
  }
  heap.length=length;
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
  heap_sort(heap);
  cout<<"\nafter sort: \n"<<endl;
  print(heap);
}
