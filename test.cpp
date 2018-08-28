//#include "header.h"	//AnycodeX includes the header.h by default, needn't cancle the notation.
#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>
using namespace std;
#define N 100
char a[N],b[N];
int dp[N][N]={0};
void trace(int A,int B){
  int i=A;
  int j=B;
  while(i>=1&&j>=1){
    if(a[i-1]==b[j-1]){
      cout<<a[i-1]<<"-->";
      i--;
      j--;
    }
    else{
      if(dp[i-1][j]>dp[i][j-1]){
        i--;
      }
      else{
        j--;
      }
    }
  }
}
void print(vector<int>vv){
  int i;
  for(i=vv.size()-1;i>=0;i--){
    cout<<a[vv[i]]<<"-->";
  }
  cout<<endl;
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
int main()
{
  int i,j;
  freopen("test.txt","r+",stdin);
  scanf("%s %s",&a,&b);
  int a_len=strlen(a);
  int b_len=strlen(b);
  for(i=1;i<a_len+1;i++){
    for(j=1;j<b_len+1;j++){
      if(a[i-1]==b[j-1]){
        dp[i][j]=dp[i-1][j-1]+1;
      }
      else{
        dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
      }
    }
  }
  cout<<dp[a_len][b_len]<<endl;
  vector<int>vv;
  tracefullpath(a_len,b_len,vv);
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
