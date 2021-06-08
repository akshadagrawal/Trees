
#include<bits/stdc++.h>
using namespace std;
class Node{
    public: 
        int data;
        Node* left, *right;
        Node(int x){
            data= x;
            left=right=NULL;
        }
};
void printleft(Node* root){
    queue<Node*> q;
    int len1=1,len2=0;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        cout<<q.front()->data<<" ";
        for(int i=0 ; i< n;i ++){
            Node *p = q.front();
            q.pop();
            if(p->left) q.push(p->left);
            if(p->right) q.push(p->right);
        }
       
    }
    
}
int main(){
    /*
                    1
                2      3
             4       6      5
                        8
    */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(5);
    root->right->right->right = new Node(8);
    printleft(root);
}