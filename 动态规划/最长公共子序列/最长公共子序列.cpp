#include <bits/stdc++.h>
using namespace std;
#define N 1000
int points,edges;
char a[N];
char b[N];
// char数组从0开始，dp从1开始，要注意
int dp[N][N]={0};
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
        // 在ij未放入的时候最优基础上+1
      }
      else{
        dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        // 如果i，j放了跟没放一样，那么就跟dp[i][j-1]/dp[i-1][j]一样了
      }
    }
  }
  cout<<"\nCommon Length:"<<dp[len_a][len_b];
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
