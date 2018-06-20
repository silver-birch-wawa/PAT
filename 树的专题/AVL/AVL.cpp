#include <bits/stdc++.h>
using namespace std;
// 左支小右支大
struct Node{
    Node* left;
    Node* right;
    int num;
    int height;
    Node(){
        height=1;
        left=NULL;
        right=NULL;
        num=0;
    }
};
// 打印操作
void preorder(Node*root){
    if(root==NULL){
        return;
    }
    printf(">>>%d   %d\n",root->num,root->height);
    preorder(root->left);
    preorder(root->right);
};
// 判断LL/LR..
// 获取高度
int getHeight(Node* root){
  if(root==NULL){
    return 0;
  }
  else{
    return root->height;
  }
}
// 判断是否平衡
int getbalancevalue(Node* root){
      return getHeight(root->left)-getHeight(root->right);
}

// 对树的深度进行修改
void updateheight(Node* &root){
  root->height=max(getHeight(root->left),getHeight(root->right))+1;
  //cout<<"change:"<<max(getHeight(root->left),getHeight(root->right))<<endl;
}

//  旋转操作：
//  左支过重
void R(Node*&root){
  Node* temp=root->left;
  root->left=temp->right;
  temp->right=root;
  // 因为C还有菱形下面的深度没有改变，所以先算A的新深度，再算新根节点B的深度。
  updateheight(root);
  updateheight(temp);
  // 最后调换root指向B，结束操作。
  root=temp;
}
void L(Node*&root)
{
  Node* temp=root->right;
  root->right=temp->left;
  temp->left=root;
  updateheight(root);
  updateheight(temp);
  root=temp;
}


// 对树需要执行的插入操作
// 对树进行修改的话一定要加&
void insert(Node* &root,int num){
    if(root==NULL){
        root=new Node();
        root->num=num;
        return ;
    }
    else if(num<root->num){
        insert(root->left,num);
        // 更新沿途经过的所有节点的height，原先想用栈装所有途径的节点指针的，但是
        updateheight(root);
        // 检查平衡因子是否==2（因为左插容易造成左过长）
        if(getbalancevalue(root)==2){
            // 出现不平衡，且是LL
            if(getbalancevalue(root->left)==1){
              R(root);
            }

            if(getbalancevalue(root->left)==-1){
              // 先把左子树左旋，变成上一种情况如何再右旋。
              L(root->left);
              R(root);
            }
        }
    }
    else{
        insert(root->right,num);
        updateheight(root);
        if(getbalancevalue(root)==-2){
            // 出现不平衡，且是RL
            if(getbalancevalue(root->left)==1){
              // 先把右子树右旋，变成下一种情况如何再左旋。
              R(root->right);
              L(root);
            }

            // 出现不平衡，且是RR
            if(getbalancevalue(root->left)==-1){
              // 把右子树左旋
              L(root);
            }
        }
    }
}
int main(){
    Node* root=NULL;
    int a[]={6,5,4,3,2,1},i=0;
    for(i=0;i<6;i++)
    {
      insert(root,a[i]);
    }

    preorder(root);
}
