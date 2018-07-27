#include <iostream>
#include<map>
using namespace std;
map<int,double>a,b;
map<int,double,greater<int>>mp;
int main()
{
    int n,x;
    double y;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        a.insert(make_pair(x,y));
    }
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        b.insert(make_pair(x,y));
    }
    for(map<int,double>::iterator it=a.begin();it!=a.end();it++)
        for(map<int,double>::iterator st=b.begin();st!=b.end();st++)
        {
            x=it->first+st->first;
            y=it->second*st->second;
            if(mp.find(x)!=mp.end())
                mp[x]+=y;
            else
                mp.insert(make_pair(x,y));
        }
    for(map<int,double,greater<int>>::iterator it=mp.begin();it!=mp.end();)
    {
        if(it->second==0)
            it=mp.erase(it);
        else
            it++;
    }
    cout<<mp.size();
    for(map<int,double,greater<int>>::iterator it=mp.begin();it!=mp.end();it++)
        printf(" %d %.1f",it->first,it->second);
    cout<<endl;
    return 0;
}
