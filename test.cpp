//#include "header.h"	//AnycodeX includes the header.h by default, needn't cancle the notation.
#include <iostream>
#include <list>
#include<algorithm>
using namespace std;
bool cmp(int a,int b){
  return a>b;
}
int main()
{
    list<int>l;
    l.push_back(11);
    l.push_back(22);
    //list<int>::iterator iter=find(l.begin(),l.end(),22);
    l.insert(l.begin(),33);
    l.sort(cmp);
    for(list<int>::iterator it=l.begin();it!=l.end();it++)
	     cout <<*it<< endl;
	return 0;
}
