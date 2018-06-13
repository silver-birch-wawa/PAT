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
        // 从后往前写，因为从前往后，j-1不是之前j-1次操作的解而是被覆盖后的j操作的解。
        for(j=volumn;j>=0;j--){
          if(weight[i]<=j){      // 因为一维数组的原因所以可以不用f[j]=f[j-1];因为不动就是默认f[j-1];
            if(f[j-weight[i]]+value[i]>f[j]){
                path[i][j]=true;
                f[j]=f[j-weight[i]]+value[i];
                // f[j]=max(f[j-weight[i]]+value[i],f[j]);  如果不需要打印路径的话
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

    cout<<"打印路径(反方向打印): 因为从头开始的话，它无法知道i+1的volmn应该是哪个-->既可以是平移不变也可以是+=weight[i+1]"<<endl;
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
