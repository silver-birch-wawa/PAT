#include <bits/stdc++.h>
using namespace std;
//int T[N]={0};
int N=10000;
int main() {
  char a[N]="APPAPTAT";
  //scanf("%s",a);
  int PA=0,PAT=0,A=0,i=0;
  long long count=0;
  for(i=0;i<strlen(a);i++){
     if(a[i]=='P'){
         PA++;
     }
     else if(a[i]=='A'){
        A=PA;
     }
     else{
         PAT+=A;
     }
  }
  printf("%ld\n",PAT%1000000007);
  return 0;
}
