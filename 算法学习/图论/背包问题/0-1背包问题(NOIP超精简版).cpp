#include <bits/stdc++.h>
using namespace std;
int main(){
      int i,j,number,volumn;
      scanf("%d %d",&number,&volumn);

      int weight[100];
      int value[100];
      int v;
      int f[100];
      bool path[100][100]={false};
      for(i=0;i<100;i++){
        f[i]=0;
      }

      for(i=1;i<number+1;i++){
        scanf("%d",&v);
        value[i]=v;
      }

      for(i=1;i<number+1;i++){
        scanf("%d",&v);
        weight[i]=v;
      }

      for(i=1;i<=number;i++){
        // �Ӻ���ǰд����Ϊ��ǰ����j-1����֮ǰj-1�β����Ľ���Ǳ����Ǻ��j�����Ľ⡣
        for(j=volumn;j>=0;j--){
          if(weight[i]<=j){      // ��Ϊһά�����ԭ�����Կ��Բ���f[j]=f[j-1];��Ϊ��������Ĭ��f[j-1];
            if(f[j-weight[i]]+value[i]>f[j]){
                path[i][j]=true;
                f[j]=f[j-weight[i]]+value[i];
                // f[j]=max(f[j-weight[i]]+value[i],f[j]);  �������Ҫ��ӡ·���Ļ�
            }
          }
        }
      }

//    for(j=0;j<=volumn;j++){
//        cout<<f[j]<<"\t";
//    }
    cout<<endl;

    cout<<"max="<<f[volumn]<<endl;

    cout<<endl;

    cout<<"��ӡ·��(�������ӡ): ��Ϊ��ͷ��ʼ�Ļ������޷�֪��i+1��volmnӦ�����ĸ�-->�ȿ�����ƽ�Ʋ���Ҳ������+=weight[i+1]"<<endl;
    for(i=number;i>0;i--){
        if(path[i][volumn]==true){
            cout<<1<<"\t";
            volumn-=weight[i];
        }
        else{
            cout<<0<<"\t";
        }
    }

}
