#include <bits/stdc++.h>
using namespace std;
#define N 1000
int dp[N][N]={0};
char a[N];
char b[N];
int main(){
  int i,j;
  int max_length=0;
  scanf("%s %s",&a,&b);
  int len_a=strlen(a);
  int len_b=strlen(b);
  int end_a=0;
  int end_b=0;
  for(i=1;i<len_a+1;i++){
    for(j=1;j<len_b+1;j++){
      if(a[i-1]==b[j-1]){
        dp[i][j]=dp[i-1][j-1]+1;
        if(max_length<dp[i][j]){
          max_length=dp[i][j];
          end_a=i;
          end_b=j;
        }
      }
    }
  }
  cout<<"max:"<<max_length<<endl;
  cout<<"end:"<<end_a-1<<"  "<<end_b-1<<endl;
}

/*
absdsdwgf 89dkdslgldj2
*/
