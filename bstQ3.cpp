#include<iostream>
using namespace std;
class node {
public:
int data;
node*left;
node*right;
node(int val){
data= val;
left=right=nullptr;
}
};
class bst{
public:
node*root;
bst(){
root=nullptr;
}
node* insertnode(node* n, int val) {
if (n == nullptr) {
return new node(val);
}

if (val < n->data){
 n->left = insertnode(n->left, val);
 }
else if (val > n->data){
n->right = insertnode(n->right, val);
}
return n;
}
void insertnode(int val) {
root = insertnode(root, val);
}
node*delnode(node*root,int key){
if(root==nullptr){
    return nullptr;
}
if(key->data<root->data){
    root=root->left;
}
else if(key->data>root->data){
    root=root->right;
}
else{
if(root->left==nullptr){
    node*temp=root->right;
    delete root;
    return temp;
}
if(root->right==nullptr){
    node*temp=root->left;
    delete root;
    return temp;
}
 node*succ=root->right;
 while(succ->left!=nullptr){
    succ=succ->left;
 }
root->data=succ->data;
root->right=delnode(root->right,succ->data);
}
return root;
}



};
