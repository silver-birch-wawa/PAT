#include <bits/stdc++.h>
using namespace std;
int main(){
  int i,j,number,volumn;
  scanf("%d %d",&number,&volumn);

  int weight[100]; //��¼ÿ����Ʒ������
  int value[100];  //��¼ÿ����Ʒ�ļ�ֵ
  int v;
  int f[100][100]; // ��¼value������

  for(i=1;i<number+1;i++){
    scanf("%d",&v);
    value[i]=v;
  }

  for(i=1;i<number+1;i++){
    scanf("%d",&v);
    weight[i]=v;
  }

  for(i=1;i<=number;i++){
    for(j=0;j<=volumn;j++){   // �����0��ʼ����Ϊj-weight[i]�����0
      f[i][j]=f[i-1][j];
      if(weight[i]<=j&&f[i-1][j-weight[i]]+value[i]>f[i][j]){
        f[i][j]=f[i-1][j-weight[i]]+value[i];
      }
    }
  }

  cout<<"��ӡf����:"<<endl;
  for(i=1;i<=number;i++){
    for(j=0;j<=volumn;j++){
        cout<<f[i][j]<<"\t";
    }
    cout<<endl;
  }
  cout<<endl;


  cout<<"��ӡѡ�еĽڵ�:"<<endl;
  j=volumn;
  bool x[100];
  for(i=0;i<=volumn;i++){
    f[0][i]=0;
  }
  for(i=number;i>0;i--){
    if(f[i][j]==f[i-1][j]){
        x[i]=false;
    }
    else{
        x[i]=true;
        j=j-weight[i];
    }
  }

  for(i=1;i<=number;i++){
    cout<<x[i]<<"\t";
  }
  cout<<endl;
  cout<<"����ֵ:"<<f[number][volumn];
}
