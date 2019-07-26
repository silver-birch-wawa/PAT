#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<vector>
#include<map>
#include <unordered_map>
using namespace std;
#define N 10000000000
int prime(int num){
    int i=0;
    if(num==3||num==2){
        return num;
    }
    if(num==1||num==0){
        return 404;
    }
    for(i=2;i*i<=num;i++){
        if(num%i==0){
            return 404;
        }
    }
    return num;
}
int main(){
    int a,b,i,j,score;
    string input;
    // vector<int>v(N);
    cin>>a>>b;
    cin>>input;
    for(i=0;i<input.size()-b+1;i++){
        int num=atoi(input.substr(i,b).c_str());
        string ans=to_string(prime(num));
        if(ans!="404"){
            for(j=0;j<b-ans.size();j++){
                printf("%d",0);
            }
            printf("%s\n",ans.c_str());
            return 0;
        }
    }
    cout<<404<<endl;
}
```

![image.png](https://upload-images.jianshu.io/upload_images/4559317-4098e658e6e048f3.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

---

#### 使用米勒-拉宾（Miller-Rabin）法：
使用自上至下的方法（网上很多用的自下至上，感觉我的这个方法理解起来更容易一些）
(据说更快，但是似乎测试数据不够大，优势不明显)
```
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
LL aPowb(long long a,long long p,long long b){
    if(p==0){
        return 1;
    }
    if(p&1){
        // 奇数
        long long g=aPowb(a,p/2,b);
        return ((a*g%b)*g)%b;
    }
    else{
        long long g=aPowb(a,p/2,b);
        return (g*g)%b;
    }
}
int prime(int num){
    if(num&1!=1||num==1){
        return 404;
    }
    if(num==2){
        return 2;
    }
    int k=0,i=0,j=0;
    int c=num-1;
    while((c&1)==0){
        c>>=1;
        k++;
    }
    for(i=0;i<20;i++){
        c=num-1;
        // 生成20个随机数将错误率降低至(1/4)^20
        long long r=rand()%(num-2)+2;
        long long y=aPowb(r,c,num);
        if(y!=1){
            return 404;
        }
        // cout<<r<<" "<<c<<" "<<num<<" "<<y<<endl;
        j=k;
        while(j>0){
            j--;
            c/=2;
            y=aPowb(r,c,num);
            // cout<<r<<" "<<c<<" "<<num<<" "<<y<<endl;            
            if(y==1){

            }
            else if(y==num-1){
                break;
            }
            else{
                return 404;
            }
        }
    }
    return num;
}
int main(){
    int a,b,i,j;
    string input;
    cin>>a>>b;
    cin>>input;
    for(i=0;i<input.size()-b+1;i++){
        int num=atoi(input.substr(i,b).c_str());
        string ans=to_string(prime(num));
        if(ans!="404"){
            for(j=0;j<b-ans.size();j++){
                printf("%d",0);
            }
            printf("%s\n",ans.c_str());
            return 0;
        }
    }
    cout<<404<<endl;
}