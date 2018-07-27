#include <bits/stdc++.h>
using namespace std;
int main(){
  int i,j,number,volumn;
  scanf("%d %d",&volumn,&number);

  int weight[100]; //记录每个物品的质量
  int value[100];  //记录每个物品的价值
  int v,w;
  int f[100]; // 记录value的数组

  bool path[100][100]={false};  // 记录路径

  for(i=0;i<100;i++){
    f[i]=0;
  }

  for(i=1;i<number+1;i++){
    scanf("%d %d",&w,&v);
    weight[i]=w;
    value[i]=v;
  }

  for(i=1;i<=number;i++){
    for(j=weight[i];j<=volumn;j++){   // 必须从0开始，因为j-weight[i]会等于0
        if(j-weight[i]>=0&&f[j]<f[j-weight[i]]+value[i]){
            path[i][j]=true;
            f[j]=f[j-weight[i]]+value[i];
        }
    }
  }
  cout<<endl;
  cout<<"最优值:"<<f[volumn]<<endl;

  cout<<"打印选中的节点:"<<endl;
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
