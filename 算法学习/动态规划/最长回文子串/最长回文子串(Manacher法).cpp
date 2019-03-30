#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
#define N 100
int mark[N]={0};
// 串的半径 @#a#a#a#*的半径为3，半径等于a的数量 @#a#a#*的半径为2，半径等于a的数量

int ans=0;
// 记录最长串长

void check(vector<int>&v,int num){
    if(mark[num]!=0){
        // 半径已经确定直接返回
        return;
    }
    int j=0,i=1,len=min(num,int(v.size())-1-num);
    // len 为最大可能半径
    while(i<len+1){
        if(v[num+i]!=v[num-i]){
            break;
        }
        i++;
    }
    // 因为在两端插入了@和*，所以避免了2222全匹配然后未经过break的情况（之前把赋值放在break里面然后没执行）
    mark[num]=i-1;
    ans=max(mark[num],ans);
    for(j=1;j<=mark[num];j++){
            mark[num+j]=min(mark[num-j],len-j);
            // 当p2的右边界跟mark[num]+num重合时，manacher算法只能帮你算出p2半径的最小可能，实际可能比len-j更大
            // 不重复的话就是mark[num-j]/len-j
            if(j+mark[num+j]==mark[num]){
                while(v[num+j+mark[num+j]+1]==v[num+j-mark[num+j]-1]){mark[num+j]++;}
            }
            ans=max(mark[num+j],ans);
    }
}
int main(){
    int i=0;
    vector<int>v;
    i=getchar();
    v.push_back('@');
    v.push_back('#');
    v.push_back(i);
    while(1){
        i=getchar();
        if(i=='\n'){
            break;
        }
        v.push_back('#');
        v.push_back(i);
    }
    v.push_back('#');
    v.push_back('*');
    for(i=0;i<v.size();i++){
        check(v,i);
    }
    cout<<ans;
}


/*
cabadabae
内包对称

abacabe
外突左对称右不一定
*/
