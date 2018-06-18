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
int porder[1000]={0};
int start=0;
void preorder1(Node* root){
    if(root==NULL){
        return;
    }
    porder[start++]=root->num;
    //cout<<"??"<<start<<endl;
    preorder1(root->left);
    preorder1(root->right);
}
int start1=0;
void preorder2(Node* root){
    if(root==NULL){
        return;
    }
    porder[start1++]=root->num;
    //cout<<"??"<<start<<endl;
    preorder2(root->right);
    preorder2(root->left);
}
bool post=true;
// not mirror
void postorder1(Node* root){
    if(root==NULL){
        return;
    }
    //cout<<"??"<<start<<endl;
    postorder1(root->left);
    postorder1(root->right);
    if(post==true){
        cout<<root->num;
        post=false;
    }
    else{
        cout<<" "<<root->num;
    }
}
// mirror
void postorder2(Node* root){
    if(root==NULL){
        return;
    }
    //cout<<"??"<<start<<endl;
    postorder2(root->right);
    postorder2(root->left);
    if(post==true){
        cout<<root->num;
        post=false;
    }
    else{
        cout<<" "<<root->num;
    }
}
void in(Node* root,int num){
    if(root==NULL){
        return;
    }
    //Node* pre=root;
    while(root!=NULL){
        //pre=root;
        if(num>=root->num){
            if(root->right==NULL){
                root->right=new Node();
                (root->right)->num=num;
                return;
            }
            root=root->right;
        }
        else{
            if(root->left==NULL){
                root->left=new Node();
                (root->left)->num=num;
                return;
            }
            root=root->left;
        }
    }
}
int main(){
    int i,j;
    int input;
    int a[1000]={0};
    scanf("%d",&input);
    if(input==0){

    }
    for(i=0;i<input;i++){
        scanf("%d",&j);
        a[i]=j;
        //cout<<a[i]<<endl;
    }
    Node*root=new Node();
    root->num=a[0];

    for(i=1;i<input;i++){
        in(root,a[i]);
    }

    preorder1(root);

    bool signal1=true,signal2=true;
    for(i=0;i<input;i++){
        if(a[i]!=porder[i]){
            signal1=false;
            break;
        }
    }
    if(signal1==false){
        //reverse(porder,porder+input);
        preorder2(root);
        for(i=0;i<input;i++){
            if(a[i]!=porder[i]){
                signal2=false;
                break;
            }
        }
    }
    //cout<<signal1<<"???????????????"<<signal2;
    if(signal1==false&&signal2==false){
        cout<<"NO";
    }
    else if(signal1==true){
        cout<<"YES"<<endl;
        postorder1(root);
    }
    else if(signal2==true){
        cout<<"YES"<<endl;
        postorder2(root);
    }

}
/*
7
6 8 2 9 1 4 7


7
8 10 11 8 6 7 5
*/
