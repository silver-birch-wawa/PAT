#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;
priority_queue<int>q;                 //c++STL������ȶ��У����ȶ�������Ԫ�شӶ������ײ����ǴӴ�С
int main()
{
    int n,i,x,a=0,t;
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>x;
        q.push(-x);                  //���ϸ��ű�֤����������Ԫ������С����������
    }
    for(i=1; i<n; i++)
    {
        t=q.top();                  //t��ȡ���Ƕ�����С���������ĺ�,Ҳ����ÿ���ƶ��ķѵ�����ֵ
        a-=q.top();                 //a��ȡ�����ܵ�����ֵ
        q.pop();                    //ɾ����һ��Ԫ��
        t+=q.top();
        a-=q.top();
        q.pop();                    //ɾ���ڶ���Ԫ��
        q.push(t);                  //����һ��Ԫ����ڶ���Ԫ�صĺͼ������������
    }
    cout<<a;
    return 0;
}
