#include <bits/stdc++.h>
using namespace std;
// ���ֵ
#define N 100010
// ��Ĵ�С
const int sqrtN=316;

vector<int>s;

int block[N]={0};
// �洢�������,��ΪsqrtN�ᱨ��....
int table[N]={0};
// �洢��Ӧȡֵ������

void findMedian(){
  if(s.empty()){
    cout<<"Invalid"<<endl;
    return;
  }
  int i,j;
  int counts=0;
  int target=0;
  if(s.size()&1){
    // ����
    target=(s.size()+1)/2;
  }
  else{
    // ż��
    target=s.size()/2;
  }
  for(i=0;i<sqrtN;i++){
    counts+=block[i];
    if(counts>=target){
      counts-=block[i];
      // �����K��ֵ���ܵĿ�ʼ-������ֵ
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
  // ��ֵ--
  table[tp]--;
  // ��ֵ--
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
  // ����ժȥ\nҪ��Ȼ��Ӱ�쵽����Ķ�ȡ

  // ���ϵķ���ֻ���ڸ����������ʱ�����Ͷ��ȡ�ɣ��ַ���������û���cin.getline(input,N)+string�ķ�ʽ
  for(i=0;i<times;i++){
    scanf("%s",input);
    // Ҫ�ж��ַ��������Ҫ��string==string,������char[]+strcmp��ʡǮ
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
