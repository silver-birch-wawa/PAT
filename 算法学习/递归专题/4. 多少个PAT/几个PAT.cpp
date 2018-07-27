#include <bits/stdc++.h>
using namespace std;
#define N 100000
int A[100000]={0};
//int T[N]={0};
int main() {
  int i,j,k;
  char a[N]="APPAPT";
  scanf("%s",a);
  //scanf("%s",a);
  int p=0,t=0;
  long long count=0;
  for(i=0;i<strlen(a);i++){
    if(a[i]=='P'){
      p++;
    }
    else if(a[i]=='A'){
      A[i]=p;
    }
  }
  for(i=strlen(a)-1;i>-1;i--){
    if(a[i]=='T'){
      t++;
    }
    else if(a[i]=='A'){
      A[i]*=t;
      count+=A[i];
    }
  }
  printf("%ld",count%1000000007);
  return 0;
}
