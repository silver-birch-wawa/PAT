#include <bits/stdc++.h>
using namespace std;
int main(){
  int i,j,number,volumn;
  scanf("%d %d",&volumn,&number);

  int weight[100]; //记录每个物品的质量
  int value[100];  //记录每个物品的价值
  int limit[100];
  int v,w,l;
  int f[100]; // 记录value的数组

  bool path[100][100]={0};  // 记录路径

  for(i=0;i<100;i++){
    f[i]=0;
  }

  j=1;
  int c=0;
  for(i=1;i<number+1;i++){
    scanf("%d %d %d",&w,&v,&l);
    if(l>=1&&w*l<=v){
        // 01背包问题处理，逐个压入数组
        for(c=0;c<l;c++){
            weight[j]=w;
            value[j]=v;
            limit[j]=1;
            j++;
        }
    }
    else{
        // 完全背包问题处理
        weight[j]=w;
        value[j]=v;
        limit[i]=0;
        j++;
    }
  }
  number=j-1;
  for(i=1;i<=number;i++){
    if(limit[i]==0){
        // 完全背包问题展开
        int signal=0;
        for(j=weight[i];j<=volumn;j++){   // 必须从头开始，因为j-weight[i]会等于0
            if(j-weight[i]>=0&&f[j]<f[j-weight[i]]+value[i]){
                // 如果里面已经有i，则-weight+weight的value不变，所以只可能是替换性添加一个i
                path[i][j]=1;
                f[j]=f[j-weight[i]]+value[i];
            }
        }
    }
    else{
        // 0-1背包问题展开
        for(j=volumn;j>=weight[i];j--){
                if(j>=weight[i]&&f[j]<f[j-weight[i]]+value[i]){
                    path[i][j]=1;
                    f[j]=f[j-weight[i]]+value[i];
                }
        }
    }
  }
  cout<<endl;
  cout<<"最优值:"<<f[volumn]<<endl;

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
  getchar();
}
