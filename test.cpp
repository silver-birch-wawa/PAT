#include <bits/stdc++.h>
using namespace std;
#define N 1000
int dp[N]={0};
char a[N];
char b[N];
int main(){
  int i,j;
  int max_length=0;
  scanf("%s",&a);
  //getchar();
  scanf("%s",&b);
  int len_a=strlen(a);
  int len_b=strlen(b);
  int end_a=0;
  int end_b=0;
  for(i=1;i<len_a+1;i++){
    for(j=len_b;j>=1;j--){
      if(a[i-1]==b[j-1]){
        dp[j]=dp[j-1]+1;
        if(max_length<dp[j]){
          max_length=dp[j];
          end_a=i;
          end_b=j;
        }
        // else{
        //   dp[]
        // }
      }
    }
  }
  for(i=end_a-1;i>end_a-1-max_length;i--){
    cout<<">>"<<a[i];
  }
  cout<<"max:"<<max_length<<endl;
  cout<<"end:"<<end_a<<"  "<<end_b<<endl;
}

/*
absdsdwgf
89dkdslgldj2

abcdef
adbcef
*/
