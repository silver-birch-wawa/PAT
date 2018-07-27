#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;
priority_queue<int>q;                 //c++STL库的优先队列，优先队列里面元素从顶部到底部都是从大到小
int main()
{
    int n,i,x,a=0,t;
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>x;
        q.push(-x);                  //加上负号保证顶部的两个元素是最小的两个整数
    }
    for(i=1; i<n; i++)
    {
        t=q.top();                  //t存取的是顶部最小的两个数的和,也就是每次移动耗费的体力值
        a-=q.top();                 //a存取的是总的体力值
        q.pop();                    //删除第一个元素
        t+=q.top();
        a-=q.top();
        q.pop();                    //删除第二个元素
        q.push(t);                  //将第一个元素与第二个元素的和加入这个队列中
    }
    cout<<a;
    return 0;
}
