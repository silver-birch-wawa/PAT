#include <bits/stdc++.h>
using namespace std;
#define N 1000
int points,edges;
char a[N];
char b[N];
// char数组从0开始，dp从1开始，要注意
int dp[N][N]={0};
// 根据原操作逆向出原路径。
void chase_path(int x,int y){
  cout<<"path: ";
  while(y>=1&&x>=1){
    if(a[x-1]==b[y-1]){
      cout<<a[x-1]<<">>";
      x--;
      y--;
    }
    else{
      if(dp[x-1][y]>dp[x][y-1]){
        x--;
      }
      else{
        y--;
      }
    }
  }
}
void print(vector<int>vv){
  int i;
  cout<<"\nFull Path:  ";
  for(i=vv.size()-1;i>=0;i--){
    cout<<a[vv[i]]<<"-->";
  }
  //cout<<endl;
}
void tracefullpath(int i,int j,vector<int>vv){
  if(i>=1&&j>=1){
    if(a[i-1]==b[j-1]){
      //cout<<"-->";
      vv.push_back(i-1);
      tracefullpath(i-1,j-1,vv);
    }
    else if(dp[i-1][j]==dp[i][j-1]){
        tracefullpath(i-1,j,vv);
        tracefullpath(i,j-1,vv);
    }
    else if(dp[i-1][j]>dp[i][j-1]){
      tracefullpath(i-1,j,vv);
    }
    else{
      tracefullpath(i,j-1,vv);
    }
  }
  else{
    print(vv);
    return;
  }
}
int main() {
  int i,j;
  scanf("%s %s",&a,&b);
  int len_a=strlen(a);
  int len_b=strlen(b);
  // 获取字符串长度

  for(i=1;i<len_a+1;i++){
    for(j=1;j<len_b+1;j++){
      if(a[i-1]==b[j-1]){
        // char数组从0开始，所以要a/b要-1
        dp[i][j]=dp[i-1][j-1]+1;
        // 在ij未放入的时候最优基础(i-1,j-1)上+1
      }
      else{
        dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        // 如果i，j放了跟没放一样，那么就跟dp[i][j-1]/dp[i-1][j]一样了(推理见blog)
      }
    }
  }
  cout<<"\nCommon Length:"<<dp[len_a][len_b]<<endl;
  chase_path(len_a,len_b);
  vector<int>vv;
  tracefullpath(len_a,len_b,vv);
  return 0;
}

/*
abcfbc abfcab
programming contest
abcd mnp

4
2
0
*/
