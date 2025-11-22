#include <iostream>
using namespace std;


class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};


class BST {
public:
    Node* root;

    BST() {
        root = nullptr;
    }


Node* insertnode(Node* node, int val) {
        if (node == nullptr) {
            return new Node(val);
        }

        if (val < node->data)
            node->left = insertnode(node->left, val);
        else if (val > node->data)
            node->right = insertnode(node->right, val);


        return node;
}
void insertnode(int val) {
        root = insertnode(root, val);
    }
 Node* searchRecursive(Node* node, int key) {
        if (node == nullptr || node->data == key)
            return node;

        if (key < node->data)
            return searchRecursive(node->left, key);
        else
            return searchRecursive(node->right, key);
    }
 Node* searchRecursive(int key) {
        return searchRecursive(root, key);
    }
 Node* searchIterative(int key) {
        Node* current = root;

        while (current != nullptr) {
            if (key == current->data)
                return current;
            else if (key < current->data)
                current = current->left;
            else
                current = current->right;
        }

        return nullptr;
    }
 Node* maxNode(Node* node) {
        if (node == nullptr) return nullptr;

        while (node->right != nullptr)
            node = node->right;

        return node;
    }

    int maxElement() {
        Node* res = maxNode(root);
        if (res == nullptr) {
            cout << "Tree is empty.\n";
            return -1; // or throw exception
        }
        return res->data;
    }
Node* minNode(Node* node) {
        if (node == nullptr) return nullptr;

        while (node->left != nullptr)
            node = node->left;

        return node;
    }

    int minElement() {
        Node* res = minNode(root);
        if (res == nullptr) {
            cout << "Tree is empty.\n";
            return -1; // or throw exception
        }
        return res->data;
    }
     Node* inorderSuccessor(Node* root, Node* x) {
        if (x == nullptr) return nullptr;


        if (x->right != nullptr) {
            return minNode(x->right);
        }


        Node* succ = nullptr;
        Node* current = root;

        while (current != nullptr) {
            if (x->data < current->data) {
                succ = current;
                current = current->left;
            } else if (x->data > current->data) {
                current = current->right;
            } else {
                break;
            }
        }
        return succ;
    }

    Node* inorderPredecessor(Node* root, Node* x) {
        if (x == nullptr) return nullptr;


        if (x->left != nullptr) {
            return maxNode(x->left);
        }


        Node* pred = nullptr;
        Node* current = root;

        while (current != nullptr) {
            if (x->data > current->data) {
                pred = current;
                current = current->right;
            } else if (x->data < current->data) {
                current = current->left;
            } else {
                break;
            }
        }
        return pred;
    }


    void inorderTraversal(Node* node) {
        if (node == nullptr) return;
        inorderTraversal(node->left);
        cout << node->data << " ";
        inorderTraversal(node->right);
    }
};
int main(){
 BST tree;

    // Build a sample BST
    int arr[] = {20, 10, 5, 15, 30, 25, 35};
    for (int x : arr)
        tree.insertnode(x);

    cout << "Inorder Traversal (sorted): ";
    tree.inorderTraversal(tree.root);
    cout << "\n";

    // (a) Search
    int key = 15;
    Node* r1 = tree.searchRecursive(key);
    Node* r2 = tree.searchIterative(key);
    cout << "Recursive search for " << key << ": "
         << (r1 ? "Found" : "Not Found") << "\n";
    cout << "Iterative search for " << key << ": "
         << (r2 ? "Found" : "Not Found") << "\n";

    // (b) Max element
    cout << "Maximum element: " << tree.maxElement() << "\n";

    // (c) Min element
    cout << "Minimum element: " << tree.minElement() << "\n";

    // (d) Inorder Successor of 15
    Node* node15 = tree.searchIterative(15);
    Node* succ = tree.inorderSuccessor(tree.root, node15);
    if (succ)
        cout << "Inorder Successor of 15: " << succ->data << "\n";
    else
        cout << "Inorder Successor of 15 does not exist.\n";

    // (e) Inorder Predecessor of 15
    Node* pred = tree.inorderPredecessor(tree.root, node15);
    if (pred)
        cout << "Inorder Predecessor of 15: " << pred->data << "\n";
    else
        cout << "Inorder Predecessor of 15 does not exist.\n";

    return 0;




















}
