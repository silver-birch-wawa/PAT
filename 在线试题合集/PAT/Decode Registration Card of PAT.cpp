#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include <unordered_map>
#include<map>
#include<vector>
using namespace std;
class card{
    public:
    string s;
    int t;
};
bool cmp(card&a,card&b){
    if(a.t==b.t){
        return a.s<b.s;
    }
    else{
        return a.t>b.t;
    }
}
int main(){
    int i,j,a,b;
    cin>>a>>b;
    string s;
    int score;
    vector<card>v;
    for(i=0;i<a;i++){
        cin>>s>>score;
        card c;
        c.s=s;
        c.t=score;
        v.push_back(c);
    }
    int type;
    string input;
    for(j=1;j<=b;j++){
        vector<card>ans;
        cin>>type>>input;
        printf("Case %d: %d %s\n", j, type, input.c_str());
        int count=0,sum=0;
        if(type==1){
            for(i=0;i<v.size();i++){
                if(v[i].s[0]==input[0]){
                    ans.push_back(v[i]);
                }
            }
        }
        else if(type==2){
            for(i=0;i<v.size();i++){
                if(v[i].s.substr(1,3)==input){
                    count++;
                    sum+=v[i].t;
                }
            }
            if(count!=0){
                printf("%d %d\n",count,sum);
            }
        }
        else{
            unordered_map<string,int>m;
            for(i=0;i<v.size();i++){
                if(v[i].s.substr(4,6)==input){
                   m[v[i].s.substr(1,3)]++;
                }
            }
            for(auto it:m){
                card c;
                c.s=it.first;
                c.t=it.second;
                ans.push_back(c);
            }
        }
        if((ans.size()==0&&type!=2)||(count==0&&type==2)){
            printf("NA\n");
        }
        else{
            sort(ans.begin(),ans.end(),cmp);
            if(type==1){
                for(i=0;i<ans.size();i++)
                printf("%s %d\n",ans[i].s.c_str(),ans[i].t);
            }
            else if(type==3){
                for(i=0;i<ans.size();i++)
                printf("%s %d\n",ans[i].s.c_str(),ans[i].t);                
            }
        }
    }
}
```

---

#### 错误代码：

```
#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<vector>
#include<map>
#include <unordered_map>
using namespace std;
class card{
    public:
    string raw;
    int grade;
    void set(string input,int score){
        raw=input;
        grade=score;
    }
};
bool cmp1(card &a,card &b){
    if(a.grade!=b.grade)
    {
        return a.grade>b.grade;
    }
    else{
        // site,time,id
        // cout<<a.raw.substr(1,11)<<endl;
        return a.raw<b.raw;
    }
}
unordered_map<string,int>m;
struct Node{
    string site;
    int times;
};
bool cmp3(Node &a,Node &b){
    if(a.times!=b.times){
        return a.times>b.times;        
    } 
    else{
        return a.site<b.site;
    }
}
int main(){
    int a,b,score;
    string s;
    vector<card>c;
    scanf("%d %d\n",&a,&b);
    //cin>>a>>b;
    int i,j;
    card temp;    
    for(i=0;i<a;i++){
        cin>>s;
        cin>>score;
        temp.set(s,score);
        c.push_back(temp);
    }
    int type;
    char cc;
    string site;    
    string time;
    for(j=0;j<b;j++){
        cin>>type;
        if(type==1){
            // case 1
            cin>>cc;
            sort(c.begin(),c.end(),cmp1);
            bool is=false;
            printf("Case %d: %d %c\n",j+1,type,cc);
            // cout<<"Case "<<j+1<<": "<<type<<" "<<cc<<endl;
            for(i=0;i<c.size();i++){
                if(c[i].raw[0]==cc){
                    is=true;
                    printf("%s %d\n",c[i].raw.c_str(),c[i].grade);
                    // cout<<c[i].raw<<" "<<c[i].grade<<endl;
                }
            }
            if(!is){
                printf("NA\n");
            }
        }
        else if(type==2){
            // case 2
            cin>>site;
            int sum=0;
            int count=0;
            for(i=0;i<c.size();i++){
                if(c[i].raw.substr(1,3)==site){
                    sum+=c[i].grade;
                    count++;
                }
            }
            cout<<"Case "<<j+1<<": "<<type<<" "<<site<<endl;
            if(count==0){
                printf("NA\n");
            }
            else{
                printf("%d %d\n",count,sum);
                // cout<<count<<" "<<sum<<endl;
            }
        }
        else if(type==3){
            // case 3
            cin>>time;
            for(i=0;i<c.size();i++){
                if(c[i].raw.substr(4,6)==time){
                    // if(m.count(c[i].raw.substr(1,3))==0){
                    //     m[c[i].raw.substr(1,3)]=1;
                    // }
                    // else{
                    //     m[c[i].raw.substr(1,3)]+=1;
                    // }
                    m[c[i].raw.substr(1,3)]++;
                }
            }
            vector<Node>v;
            for(auto it: m){
                Node node;
                node.site=it.first;
                node.times=it.second;
                v.push_back(node);
            }           
            printf("Case %d: %d %s\n",j+1,type,time.c_str()); 
            // cout<<"Case "<<j+1<<": "<<type<<" "<<time<<endl;
            if(v.size()==0){
                printf("NA\n");
            }
            else{
                sort(v.begin(),v.end(),cmp3);
                for(i=0;i<v.size();i++){
                    printf("%s %d\n",v[i].site.c_str(),v[i].times);
                    // cout<<v[i].site<<" "<<v[i].times<<endl;
                }
            }
        }
        else{
                printf("NA\n");
        }
    }
}