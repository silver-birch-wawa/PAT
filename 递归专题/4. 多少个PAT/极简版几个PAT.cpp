#include <bits/stdc++.h>
using namespace std;
//int T[N]={0};
int N=100000;
int main() {
  char a[N];
  scanf("%s",a);
  //scanf("%s",a);
  long long PA=0,PAT=0,A=0,i=0;
  long long count=0;
  for(i=0;i<strlen(a);i++){
     if(a[i]=='P'){
         PA++;
     }
     else if(a[i]=='A'){
        A+=PA;
     }
     else{
         PAT+=A%1000000007;
     }
  }
  printf("%ld",PAT%1000000007);
  return 0;
}
