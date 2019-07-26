#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<vector>
#include<map>
#include<cstdlib>
#include <unordered_map>
using namespace std;
typedef long long LL;
unordered_map<int,int>m;
// 后面的int记录在先序遍历中的位置
void deal(vector<int>&v1,vector<int>&v2,int left,int right,int &a,int &b){
    // a和b是对应的位置不是对应的值,看中序遍历的v1的相对位置即可判断。
    // left还有right用于在先序数组v2中查找用于middle的项
    int middle=m[v2[left]];
    if(middle==a){
        printf("%d is an ancestor of %d.\n",v1[a],v1[b]);
        return;
    }
    else if(middle==b){
        printf("%d is an ancestor of %d.\n",v1[b],v1[a]); 
        return;       
    }
    else if((middle>a&&middle<b)||(middle>b&&middle<a)){
        printf("LCA of %d and %d is %d.\n",v1[a],v1[b],v1[middle]);
        return;
    }
    else{
        if(a>middle){
            deal(v1,v2,middle+1,right,a,b);
        }
        else if(a<middle){
            deal(v1,v2,left+1,middle,a,b);
        }
    }
}
int main(){
    int a,b,i,j,aa,bb;
    // aa,bb 存放输入次数和节点的个数，a和b存放具体的输入点对
    cin>>aa>>bb;
    int input;
    vector<int>v1,v2;
    // v1是中序，v2是先序
    for(i=0;i<bb;i++){
        cin>>input;
        v1.push_back(input);
        m[input]=i;
        // 记录先序的点在中序中的位置,这样好定位转折点
    }
    for(i=0;i<bb;i++){
        cin>>input;
        v2.push_back(input);
    }    
    for(i=0;i<aa;i++){
        cin>>a>>b;
        // key是位置不是位置对应的值
        if(!m.count(a)&&!m.count(b)){
            printf("ERROR: %d and %d are not found.\n",a,b);
        }
        else if(!m.count(a)){
            printf("ERROR: %d is not found.\n",a);
        }
        else if(!m.count(b)){
            printf("ERROR: %d is not found.\n",b);
        }
        else{
            int aa=0,bb=0;
            for(j=0;j<v1.size();j++){
                if(v1[j]==a){
                    aa=j;
                }
                else if(v1[j]==b){
                    bb=j;
                }
            }
            deal(v1,v2,0,v1.size()-1,aa,bb);
        }
    }
}

/*

6 8
7 2 3 4 6 5 1 8
5 3 7 2 6 4 8 1
2 6
8 1
7 9
12 -3
0 8
99 99

*/