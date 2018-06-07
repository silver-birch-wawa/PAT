#include <bits/stdc++.h>
using namespace std;
int main(){
      int i,j,number,volumn;
      scanf("%d %d",&number,&volumn);

      int weight[100];
      int value[100];
      int v;
      int f[100];
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
        for(j=volumn;j>=0;j--){
          //f[j-1]=f[j];
          if(weight[i]<=j){
            f[j]=max(f[j-1],f[j-weight[i]]+value[i]);
          }
        }
      }
    for(j=0;j<=volumn;j++){
        cout<<f[j]<<"\t";
    }

    cout<<endl;

    cout<<f[volumn];
}
