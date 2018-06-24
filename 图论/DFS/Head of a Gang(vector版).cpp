#include <bits/stdc++.h>
using namespace std;
typedef struct{
  int sum;
  bool passby;
  int num;
  // Node(){
  //   sum=0;
  //   num=0;
  //   passby=false;
  // }
}Node;

int circle=0;

void insert(vector<vector<Node>>&root,int point,int num){
    Node node;
    node.num=num;
    node.sum=0;
    node.passby=false;
    //cout<<"insert:"<<point<<endl;
    root[point].push_back(node);
}

void print(vector<vector<Node>>root){
  int i=0,j=0;
  for(i=0;i<circle;i++){
    for(j=0;j<root[i].size();j++){
        cout<<">>>"<<root[i][j].num<<"\t"<<root[i][j].sum<<endl;
    }
    cout<<endl;
  }
}
void DFS(vector<vector<Node>>&root,int begin,int &head,int &len,int &sum){
  int i,j;

  for(i=1;i<root[begin].size();i++){
    // cout<<"------------"<<begin<<endl;
    if(root[root[begin][i].num][0].passby==false){
      //cout<<"++++++++++++++++"<<endl;
      sum+=root[root[begin][i].num][0].sum;
      len++;
      root[root[begin][i].num][0].passby=true;

      if(root[root[begin][i].num][0].sum>root[head][0].sum){
        head=root[begin][i].num;
      }

      DFS(root,root[begin][i].num,head,len,sum);
    }
  }
}
struct res{
  int len;
  string ans;
};
bool cmp(res s1,res s2){
  return  s1.ans[0]<s2.ans[0];
}
int main(){
  vector<vector<Node>>root;
  string s[100];
  int i,K=0;
  map<string,int>m;
  scanf("%d %d",&circle,&K);

  int input;
  char a[100],b[100];

  int signal=1;

  // 需要比正常多插入一个vector
  for(i=0;i<circle+1;i++){
    vector<Node>v;
    Node node;
    node.num=i;
    node.sum=0;
    node.passby=false;
    // 理论上默认为0但是没有调用构造函数只能自己置为0了
    v.push_back(node);
    root.push_back(v);
  }

  string str1,str2;

  // 因为字典null为0，所以要从1开始编号，所以需要num+1长度的数组，遍历也要从1开始。
  for(i=0;i<circle;i++){
    scanf("%s %s %d",a,b,&input);
    str1=a;
    if(m[str1]==0){
      m[str1]=signal++;
      s[signal-1]=str1;
    }
    str2=b;

    if(m[str2]==0){
      m[str2]=signal++;
      s[signal-1]=str2;
    }
    // cout<<"----------\n";
    //     cout<<"str1:"<<m[str1]<<endl;
    //     cout<<"str2:"<<m[str2]<<endl;
    root[m[str1]][0].sum+=input;
    root[m[str2]][0].sum+=input;

    insert(root,m[str1],m[str2]);
    //cout<<"++++++";
  }
  int head=0,len=0,sum=0;

  vector<res>ss;

  for(i=1;i<circle+1;i++){
    head=i;
    len=1;
    sum=root[i][0].sum;
    root[i][0].passby=true;

    DFS(root,i,head,len,sum);
    if(sum>K*2&&len>2){
      res r;
      r.len=len;
      r.ans=s[head];
      ss.push_back(r);
      // ss.push_back(s[head]);
      // ii.push_back(len);
      // cout<<s[i]<<" "<<len<<endl;
      // cout<<"start:"<<s[i]<<endl;
      // cout<<"head:"<<s[head]<<endl;
      // cout<<"len:"<<len<<endl;
      // cout<<sum/2<<endl;
      //cout<<"value:"<<root[head][0].sum<<endl;
      // cout<<endl;
    }
    //print(root);
  }
  if(ss.size()==0){
    cout<<0;
    return 0;
  }
  cout<<ss.size()<<endl;

  sort(ss.begin(),ss.end(),cmp);

  for(i=0;i<ss.size();i++){
    cout<<ss[i].ans<<" "<<ss[i].len<<endl;
  }

  // print(root);
}
