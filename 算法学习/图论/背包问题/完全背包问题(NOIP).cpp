#include <bits/stdc++.h>
using namespace std;
int main(){
  int i,j,number,volumn;
  scanf("%d %d",&volumn,&number);

  int weight[100]; //��¼ÿ����Ʒ������
  int value[100];  //��¼ÿ����Ʒ�ļ�ֵ
  int v,w;
  int f[100]; // ��¼value������

  bool path[100][100]={false};  // ��¼·��

  for(i=0;i<100;i++){
    f[i]=0;
  }

  for(i=1;i<number+1;i++){
    scanf("%d %d",&w,&v);
    weight[i]=w;
    value[i]=v;
  }

  for(i=1;i<=number;i++){
    for(j=weight[i];j<=volumn;j++){   // �����0��ʼ����Ϊj-weight[i]�����0
        if(j-weight[i]>=0&&f[j]<f[j-weight[i]]+value[i]){
            path[i][j]=true;
            f[j]=f[j-weight[i]]+value[i];
        }
    }
  }
  cout<<endl;
  cout<<"����ֵ:"<<f[volumn]<<endl;

  cout<<"��ӡѡ�еĽڵ�:"<<endl;
  while(i>=1&&volumn>=0){
      if(path[i][volumn]==true){
        cout<<"weight:"<<weight[i]<<" num:"<<1<<endl;
        volumn-=weight[i];
      }
      else{
        i--;
        //cout<<0<<"\t";
      }
  }
}
