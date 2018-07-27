#include <bits/stdc++.h>
using namespace std;
#define N 6

struct node{
   int x,y;
   node(){
     x=0;
     y=0;
   }
}Node;

int n=N,m=N+1;  // 矩阵x和y的大小
int matrix[N][N+1]={0};  // 存储矩阵中的元素

bool info[N][N+1]={false};  // 标记是否已读

bool judge(int x,int y){
    // 未越界且未被访问的留下其他剔除
    if(x>=n||x<0||y<0||y>=m){
        return false;
    }
    else if(info[x][y]==true||matrix[x][y]==0){
        return false;
    }
    else if(info[x][y]==false&&matrix[x][y]==1){
        // 矩阵中有值而且未被访问过则置为true
        info[x][y]=true;
        //cout<<"pass: "<<x<<","<<y<<endl;
        return true;
    }
}
void BFS(int x,int y){
    queue<node>q;
    int i;
    int x1,y1;

    info[x][y]=true;

    Node.x=x;
    Node.y=y;

    q.push(Node);

    while(q.empty()!=true){
        // 取头部的数据然后删除
        node top=q.front();
        //cout<<"Node: "<<top.x<<"\t"<<top.y<<endl;
        q.pop();

        x1=top.x;
        y1=top.y+1;
        if(judge(x1,y1)){
            Node.x=x1;
            Node.y=y1;
            q.push(Node);
        }
        x1=top.x+1;
        y1=top.y;
        if(judge(x1,y1)){
            Node.x=x1;
            Node.y=y1;
            q.push(Node);
        }
        x1=top.x;
        y1=top.y-1;
        if(judge(x1,y1)){
            Node.x=x1;
            Node.y=y1;
            q.push(Node);
        }
        x1=top.x-1;
        y1=top.y;
        if(judge(x1,y1)){
            Node.x=x1;
            Node.y=y1;
            q.push(Node);
        }
        //cout<<"Node: "<<x1<<"\t"<<y1<<endl;
    }
}
void print(){
   int i,j;
   for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            //matrix[i][j]=a[i*(N+1)+j];
            cout<<info[i][j]<<"\t";
        }
        cout<<endl;
   }
}
int main(){
    int i,j,a[]={0,1,1,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,1,1,0,1,1,1,0,1,0,0,1,1,1,1,0,0,0};

    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            matrix[i][j]=a[i*(N+1)+j];
            cout<<matrix[i][j]<<"\t";
        }
        cout<<endl;
    }
    int ans=0;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(matrix[i][j]==1&&info[i][j]==false){
               ans++;
               cout<<"Temp: "<<i<<","<<j<<endl;
               BFS(i,j);
            }
        }
        //cout<<endl;
    }
    cout<<ans++;
}
