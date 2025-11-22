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
class bt{
public:
node*root;
bt(){
root=nullptr;
}
node*createnode(int val){
   return new node(val);
}
void preorder(node*n){
if ( n == nullptr) return;
cout<<n->data<<" ";
preorder(n->left);
preorder(n->right);
}
void inorder(node*n){
if ( n == nullptr) return;
inorder(n->left);
cout<<n->data<<" ";
inorder(n->right);
}
void postorder(node*n){
if ( n == nullptr) return;
postorder(n->left);
postorder(n->right);
cout<<n->data<<" ";
}

};
int main(){
bt tree;
tree.root = tree.createnode(1);
    tree.root->left = tree.createnode(2);
    tree.root->right = tree.createnode(3);
    tree.root->left->left = tree.createnode(4);
    tree.root->left->right = tree.createnode(5);

    cout << "Preorder Traversal: ";
    tree.preorder(tree.root);

    cout << "\nInorder Traversal: ";
    tree.inorder(tree.root);

    cout << "\nPostorder Traversal: ";
    tree.postorder(tree.root);

    return 0;
}
