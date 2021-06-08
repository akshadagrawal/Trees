//Create a binary searh tree
#include<bits/stdc++.h>
using namespace std;

class Node{
    public: 
        int data;
        Node* left, *right;
        Node(int x){
            data=x;
            left= NULL;
            right= NULL;
        }
};
class BST{
    Node* root;
    public :
        BST(){
            root= NULL;
        }
        void insert(int x);
        void print();
        bool search(int x);
        bool deleteNode (int x);
    private : 
        void insert(int x, Node*);
        void print(Node*);
        bool search(int x, Node* );
        Node* deleteNode (int x, Node* );


};
void BST ::insert(int x){
    if(root ==NULL) {
        root=new Node(x);
    }
    else {
        insert(x, root);
    }
}
void BST:: insert(int x, Node* root){
    if(x < root->data ){
        if(root->left)
            insert(x, root->left);
        else {
            root->left= new Node(x);
        }
    }
    else if( x >= root->data){
        if(root -> right){
            insert(x, root->right);
        }
        else {
            root->right= new Node(x);
        }
    }
}
void BST:: print(){
    cout<<"Level Order Traversal: "<<endl;
    print(root);
    cout<<endl;
}
void BST:: print(Node* root){
    if(root ==NULL) return;
    queue<Node* > q;
    q.push(root);
    while(!q.empty()){
        int n= q.size();
        for(int i=0 ;i< n; i++){
            Node *p= q.front();
            q.pop();
            cout<<p->data<<" ";
            if(p->left) q.push(p->left);
            if(p->right) q.push(p->right);
        }
        cout<<endl;
    }
}
bool BST:: search(int x){
    return search(x, root);
}
bool BST:: search(int x, Node* root){
    if(root ==NULL) return false;
    else {
        if( x ==root->data) return root;
        else if( x < root->data) return search(x, root->left);
        else return search(x, root->right);
    }
}
bool BST:: deleteNode(int x){
    return deleteNode(x, root);
}
Node* findMinVal(  Node* root){
    Node *min= root;
    while (min->left !=NULL){
        min= min->left;
    }
    return min;
    
    
}
Node* BST:: deleteNode(int x, Node* root){
    if(root ==NULL) return NULL;
    else if(root->data > x){
        root->left = deleteNode(x, root->left);
    }
    else if(root->data < x){
        root->right = deleteNode(x, root->right);
    }
    else {
        if(root->left == NULL && root->right == NULL) {
            Node * temp = root;
            delete temp;
            root= NULL;
        }
        else if(root->left ==NULL){
            Node * temp = root;
            root= root->right;
            delete temp;
        }
        else if(root->right ==NULL){
            Node* temp= root;
            root= root->left;
            delete temp;
        }
        else {
            Node * temp = findMinVal(root->right);
            root->data = temp->data;
            root->right = deleteNode(temp->data,root->right);
        }
    }
    return root;
}
int main(){
    BST b;
    b.insert(10);
    b.insert(6);
    b.insert(14);
    b.insert(8);
    b.insert(5);
    b.insert(11);
    b.insert(18);

    b.print();
    // while(1){
    //     int x;
    //     cin>>x;
    //     if(x==-1) break;
    //     cout<<(b.search(x) ? "Found" : "Not Found")<<endl;
    // }
    while(1){
        int x;
        cin>>x;
        if(x==-1) break;
        cout<<(b.deleteNode(x) ? "Deleted" : "Not Found")<<endl;
        b.print();
    }

    

}