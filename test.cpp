#include <bits/stdc++.h>
using namespace std;
string s[100];
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

vector<vector<Node> >root;
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
  Node p;

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
int main(){
  int i,K=0;
  map<string,int>m;
  scanf("%d %d",&circle,&K);

  int input;
  char a[100],b[100];

  int signal=1;

  // ��Ҫ�����������һ��vector
  for(i=0;i<circle+1;i++){
    vector<Node>v;
    Node node;
    node.num=i;
    node.sum=0;
    node.passby=false;
    // ������Ĭ��Ϊ0����û�е��ù��캯��ֻ���Լ���Ϊ0��
    v.push_back(node);
    root.push_back(v);
  }

  string str1,str2;

  // ��Ϊ�ֵ�nullΪ0������Ҫ��1��ʼ��ţ�������Ҫnum+1���ȵ����飬����ҲҪ��1��ʼ��
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

  vector<string>ss;
  vector<int>ii;

  for(i=1;i<circle+1;i++){
    head=i;
    len=1;
    sum=root[i][0].sum;
    root[i][0].passby=true;

    DFS(root,i,head,len,sum);
    if(sum>K*2&&len>2){
      ss.push_back(s[head]);
      ii.push_back(len);
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
  cout<<ss.size()<<endl;
  for(i=0;i<ss.size();i++){
    cout<<ss[i]<<" "<<ii[i]<<endl;
  }
  if(ss.size()==0){
    cout<<0;
  }
  // print(root);
}