#include <bits/stdc++.h>
using namespace std;
int main(){
  int i,j,number,volumn;
  scanf("%d %d",&volumn,&number);

  int weight[100]; //��¼ÿ����Ʒ������
  int value[100];  //��¼ÿ����Ʒ�ļ�ֵ
  int limit[100];
  int v,w,l;
  int f[100]; // ��¼value������

  bool path[100][100]={0};  // ��¼·��

  for(i=0;i<100;i++){
    f[i]=0;
  }

  j=1;
  int c=0;
  for(i=1;i<number+1;i++){
    scanf("%d %d %d",&w,&v,&l);
    if(l>=1&&w*l<=v){
        // 01�������⴦�����ѹ������
        for(c=0;c<l;c++){
            weight[j]=w;
            value[j]=v;
            limit[j]=1;
            j++;
        }
    }
    else{
        // ��ȫ�������⴦��
        weight[j]=w;
        value[j]=v;
        limit[i]=0;
        j++;
    }
  }
  number=j-1;
  for(i=1;i<=number;i++){
    if(limit[i]==0){
        // ��ȫ��������չ��
        int signal=0;
        for(j=weight[i];j<=volumn;j++){   // �����ͷ��ʼ����Ϊj-weight[i]�����0
            if(j-weight[i]>=0&&f[j]<f[j-weight[i]]+value[i]){
                // ��������Ѿ���i����-weight+weight��value���䣬����ֻ�������滻�����һ��i
                path[i][j]=1;
                f[j]=f[j-weight[i]]+value[i];
            }
        }
    }
    else{
        // 0-1��������չ��
        for(j=volumn;j>=weight[i];j--){
                if(j>=weight[i]&&f[j]<f[j-weight[i]]+value[i]){
                    path[i][j]=1;
                    f[j]=f[j-weight[i]]+value[i];
                }
        }
    }
  }
  cout<<endl;
  cout<<"����ֵ:"<<f[volumn]<<endl;

  for(j=0;j<=volumn;j++){
     cout<<f[j]<<"\t";
  }

  cout<<endl;
  for(i=1;i<number+1;i++){
    for(j=0;j<volumn+1;j++){
        cout<<path[i][j]<<"\t";
    }
    cout<<endl;
  }

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
  getchar();
}
