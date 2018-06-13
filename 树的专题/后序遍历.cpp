#include <bits/stdc++.h>
using namespace std;
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
void preorder(Node*root){
    //stack<Node*>s;
    //s.push(root);
    if(root==NULL){
        //cout<<"booommmm";
        return;
    }
    //printf("%d\n",root->num);
    preorder(root->left);
    //printf("%d\n",root->num);
    preorder(root->right);
    printf("%d\n",root->num);
}
void in(Node *root,int input){
    Node*p=root;
    if(root==NULL){
        root=new Node();
//      root->left=NULL;
//      root->right=NULL;
        //cout<<"mmmm????"<<endl;
        root->num=input;
        return;
    }
    while(p!=NULL){
        //cout<<"bypass"<<endl;
        if(input>(p->num)){   // ÓÒ´ó×óÐ¡
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

    //root=new Node();
    if(root==NULL){cout<<"fffffuuuuuucccckkkk"<<endl;}
    preorder(root);
}

// 6 8 2 9 1 4 7
