#include<bits/stdc++.h>
using namespace std;

// STRUCTURE OF BINARY TREE
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

// FIND THE LOWEST COMMEON ANCESTOR OF GIVEN TWO NODES
Node* lowestCommonAncestor(Node* root,Node* p,Node* q){
    if(root==NULL || root==p || root==q){
        return root;
    }
    Node* leftLCA = lowestCommonAncestor(root->left,p,q);
    Node* rightLCA = lowestCommonAncestor(root->right,p,q);
    if(leftLCA!=NULL && rightLCA!=NULL){
        return root;
    }
    if(leftLCA!=NULL){
        return leftLCA;
    }
    if(rightLCA!=NULL){
        return rightLCA;
    }
}
int main(){
    
}