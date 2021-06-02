//traversals using recursion

#include<bits/stdc++.h>
using namespace std;
class Node{
    public: 
        int data;
        Node* left, *right;
        Node(int x){
            data= x;
            left=NULL;
            right=NULL;
        }
};
void inorder(Node* root){
    if(root == NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(Node* root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node* root){
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int main(){

    /*
                1
            12      9
        5       6
    */
    Node* root = new Node(1);
    root->left = new Node(12);
    root->right = new Node(9);
    root->left->left = new Node(5);
    root->left->right = new Node(6);
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);

}