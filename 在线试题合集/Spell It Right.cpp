#include<bits/stdc++.h>
using namespace std;
void print(int num){
  switch (num) {
    case 0:cout<<"zero";break;
    case 1:cout<<"one";break;
    case 2:cout<<"two";break;
    case 3:cout<<"three";break;
    case 4:cout<<"four";break;
    case 5:cout<<"five";break;
    case 6:cout<<"six";break;
    case 7:cout<<"seven";break;
    case 8:cout<<"eight";break;
    case 9:cout<<"nine";break;
  }
}
int main(){
  int num=0;
  while(1){
    char c=getchar();
    if(c=='\n'){
      break;
    }
    else{
      num+=(c-'0');
    }
  }

  vector<int>s;
  while(num>0){
    s.push_back(num%10);
    num/=10;
  }
  if(s.size()==0){
    cout<<"zero";
    return 0;
  }
  // cout<<"size:"<<s.size()<<endl;
  int i;
  print(s[s.size()-1]);
  for(i=s.size()-2;i>=0;i--){
    cout<<" ";
    print(s[i]);
  }
}
