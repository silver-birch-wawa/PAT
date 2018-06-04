#include <bits/stdc++.h>
using namespace std;
void ftoa(float f,char a[],int m){
  sprintf(a, "%f", f); //将10.8转为字符串
}
int main()
{
  char c[2]="1";
  int num=0;
  char a[60];
  string Num;
  stack<string>s,ss,sss;
  while((c[0]=getchar())!='\n'){
     if(isdigit(c[0])){
        //cout<<"num:"<<c<<endl;
        num*=10;
        num+=c[0]-'0';
     }
     else if(c[0]!=' '){
       itoa(num,a,10);
       num=0;
       //cout<<"???:"<<a<<endl;
       s.push(a);
       //string temp(c);
       s.push(c);
     }
  }
  itoa(num,a,10);
  s.push(a);

  int i=0;
  string temp;

  // while(!s.empty()){
  //   temp=s.top();
  //   cout<<"1:"<<temp<<endl;
  //   ss.push(temp);
  //   s.pop();
  // }

  while(!s.empty()){
    //cout<<"2:"<<s.top()<<endl;
    sss.push(s.top());
    s.pop();
  }
  s=sss;


  float ans,t=0;
  //temp=atoi(ss.top().c_str());

  while(!s.empty()){
    temp=s.top();
    cout<<"1:"<<temp<<endl;
    if(temp=="*"){
      s.pop();
      t=atof(s.top().c_str());
      s.pop();
      ans=atof(ss.top().c_str());
      ss.pop();
      ans*=t;
      ftoa(ans,a,10);
      ss.push(a);
    }
    else if(temp=="/"){
      s.pop();
      t=atof(s.top().c_str());
      s.pop();
      ans=atof(ss.top().c_str());
      ss.pop();
      ans/=t;
      ftoa(ans,a,10);
      s.push(a);
    }
    else{
      ss.push(temp);
      s.pop();
    }

  }

  // while(!ss.empty()){
  //   cout<<"2:"<<ss.top()<<endl;
  //   ss.pop();
  // }

  while(!ss.empty()){
    //cout<<"2:"<<s.top()<<endl;
    s.push(ss.top());
    ss.pop();
  }
  ss=s;

  // while(!ss.empty()){
  //   cout<<"22222:"<<ss.top()<<endl;
  //   ss.pop();
  // }

  float res=atof(ss.top().c_str());
  ss.pop();
  while(!ss.empty()){
    temp=ss.top();
    cout<<"2:"<<temp<<endl;
    if(temp=="+"){
        ss.pop();
        ans=atof(ss.top().c_str());
        ss.pop();
        res+=ans;
    }
    if(temp=="-"){        // "-"而不是'-' !!!!
        ss.pop();
        ans=atof(ss.top().c_str());
        ss.pop();
        res-=ans;
        //res*=-1;
    }
  }
  cout<<"res:"<<res<<endl;
}
