#include<bits/stdc++.h>
using namespace std;
int postorder[100];
int inorder[100];
struct Node{
   Node*left;
   Node* right;
   int num;
   Node(){
       left=NULL;
       right=NULL;
       num=0;
   }
};
Node *create(int PL,int PR,int IL,int IR){
    if(PL>PR){
        return NULL;
    }
    int i,rt=postorder[PR];
    int Iroot;
    for(i=IL;i<=IR;i++){
        if(rt==inorder[i]){
            Iroot=i;
            //cout<<"Iroot:"<<i<<endl;
            break;
        }
    }
    int ir=i-1;
    int il=i+1;
    Node* root=new Node();
    root->num=rt;
    //cout<<PL<<" "<<ir-IL+PL<<" "<<IL<<" "<<ir-1<<endl;
    //cout<<ir-IL+PL+1<<" "<<PR-1<<" "<<il<<" "<<IR<<endl;
    root->left=create(PL,ir-IL+PL,IL,ir);
    root->right=create(ir-IL+PL+1,PR-1,il,IR);
    return root;
    // 返回子树的根节点。
}

void BFS(Node*root){
    queue<Node*>q;
    Node *p;
    q.push(root);
    while(!q.empty()){
        p=q.front();
        q.pop();
        cout<<p->num<<" ";
        if(p->left!=NULL){
            q.push(p->left);
        }
        if(p->right!=NULL){
            q.push(p->right);
        }
    }
}

int main(){
    int i,j,input;
    int Postorder,Inorder;
    scanf("%d",&input);
    for(i=0;i<input;i++){
        scanf("%d",&j);
        postorder[i]=j;
    }
    Postorder=i-1;

    for(i=0;i<input;i++){
        scanf("%d",&j);
        inorder[i]=j;
    }
    Inorder=i-1;
    Node*root=create(0,Postorder,0,Inorder);
    BFS(root);
}
