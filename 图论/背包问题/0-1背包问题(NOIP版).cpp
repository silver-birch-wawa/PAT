#include <bits/stdc++.h>
using namespace std;
int main(){
  int i,j,number,volumn;
  scanf("%d %d",&number,&volumn);

  int weight[100]; //记录每个物品的质量
  int value[100];  //记录每个物品的价值
  int v;
  int f[100][100]; // 记录value的数组

  for(i=1;i<number+1;i++){
    scanf("%d",&v);
    value[i]=v;
  }

  for(i=1;i<number+1;i++){
    scanf("%d",&v);
    weight[i]=v;
  }

  for(i=1;i<=number;i++){
    for(j=0;j<=volumn;j++){   // 必须从0开始，因为j-weight[i]会等于0
      f[i][j]=f[i-1][j];
      if(weight[i]<=j&&f[i-1][j-weight[i]]+value[i]>f[i][j]){
        f[i][j]=f[i-1][j-weight[i]]+value[i];
      }
    }
  }

  cout<<"打印f数组:"<<endl;
  for(i=1;i<=number;i++){
    for(j=0;j<=volumn;j++){
        cout<<f[i][j]<<"\t";
    }
    cout<<endl;
  }
  cout<<endl;


  cout<<"打印选中的节点:"<<endl;
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
  cout<<"最优值:"<<f[number][volumn];
}
