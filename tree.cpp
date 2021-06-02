//Simplest implementation of the binary tree for CP

#include<bits/stdc++.h>
using namespace std;
class Node {
   
    public:
        int data;
        Node *left, *right;
        Node(int x){
            data = x;
            left=NULL;
            right=NULL;
        }
};
class Btree{
    public:
        Node *root;
        Btree(){
            root=NULL;
        }
        Node *buildTree();
        void printTree(Node* );
};
Node* Btree:: buildTree(){
    int x;
    cin>>x;
    if(x==-1){
        return NULL;
    }
    Node* p= new Node(x);
    p->left= buildTree();
    p->right= buildTree();
    
    
    return p;
}
void Btree::printTree(Node* root){
    if(root== NULL) return;
    cout<<root->data;
    printTree(root->left);
    printTree(root->right);
}
int main(){
    Btree b;
    b.root= b.buildTree();
    b.printTree(b.root);

}