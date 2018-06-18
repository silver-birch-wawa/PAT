#include <bits/stdc++.h>
using namespace std;
// 左支小右支大
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
// 插入
void in(Node *root,int input){
    Node*p=root;
    if(root==NULL){
        root=new Node();
        root->num=input;
        return;
    }
    while(p!=NULL){
        //cout<<"bypass"<<endl;
        if(input>(p->num)){   // 右大左小
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
// 查找右子树最小的节点（仅max于num的节点）
Node* findmax(Node*root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}
// 查找左子树最大的节点（仅min于num的节点）
Node* findmin(Node*root){
    while(root->right!=NULL){
        root=root->right;
    }
    return root;
}
// 删除比较麻烦,需要查找小于该num或者大于该num的节点进行覆盖，但是为了避免节点置为NULL后树的通道中断了，就采取循环补漏的方式
// 将最后一个遍历到的（一般是num最左/最右）置为空，拆西墙补东墙（因为删除之后空了一个元素）。
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
