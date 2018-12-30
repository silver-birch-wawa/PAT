#include <bits/stdc++.h>
using namespace std;
// ��֧С��֧��
struct Node{
    Node* left;
    Node* right;
    int num;
    Node(){
        left=NULL;
        right=NULL;
        num=0;
    }
};
// ����
void in(Node *root,int input){
    Node*p=root;
    if(root==NULL){
        root=new Node();
        root->num=input;
        return;
    }
    while(p!=NULL){
        //cout<<"bypass"<<endl;
        if(input>(p->num)){   // �Ҵ���С
            if(p->right==NULL){
               p->right=new Node();
               (p->right)->num=input;
               break;
            }else{
               p=p->right;
            }
        }
        else{
            if(p->left==NULL){
                p->left=new Node();
                (p->left)->num=input;
                break;
            }
            else{
                p=p->left;
            }
        }
    }
}
// ������������С�Ľڵ㣨��max��num�Ľڵ㣩
Node* findmax(Node*root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}
// ���������������Ľڵ㣨��min��num�Ľڵ㣩
Node* findmin(Node*root){
    while(root->right!=NULL){
        root=root->right;
    }
    return root;
}
// ɾ���Ƚ��鷳,��Ҫ����С�ڸ�num���ߴ��ڸ�num�Ľڵ����и��ǣ�����Ϊ�˱����ڵ���ΪNULL������ͨ���ж��ˣ��Ͳ�ȡѭ����©�ķ�ʽ
// ������һ���������ģ�һ����num����/���ң���Ϊ�գ�����ǽ����ǽ����Ϊɾ��֮������һ��Ԫ�أ���
void del(Node* &root,int num){
    Node* l;
    Node* r;
    if(root==NULL){
        return;
    }
    if(root->num==num){
        if(root->left==NULL&&root->right==NULL){
            root=NULL;
            return;
        }
        else if(root->left!=NULL){
            l=findmin(root->left);
            root->num=l->num;
            //l=NULL;
            del(root->left,l->num);
        }
        else{
            r=findmax(root->right);
            root->num=r->num;
            //r=NULL;
            del(root->right,r->num);
        }
    }
    else if(root->num>num){
        del(root->left,num);
    }
    else{
        del(root->right,num);
    }
}
void preorder(Node*root){
    if(root==NULL){
        return;
    }
    printf("%d\n",root->num);
    preorder(root->left);
    preorder(root->right);
}
int main(){
    int i,j;
    int input;
    Node*root=new Node();
    scanf("%d",&input);
    root->num=input;

    for(i=0;i<6;i++){
      scanf("%d",&input);
      in(root,input);
    }
    del(root,4);
    preorder(root);
}

// 6 8 2 9 1 4 7
