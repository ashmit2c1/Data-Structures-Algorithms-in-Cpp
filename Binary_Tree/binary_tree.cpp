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
// TAKE RECURSIVE INPUT IN BINARY TREE
Node* takeInputRecursive(){
    int rootdata;
    cin >> rootdata;
    if(rootdata==-1){
        return NULL;
    }
    Node*root = new Node(rootdata);
    Node*leftnode = takeInputRecursive();
    Node*rightnode = takeInputRecursive();
    root->left=leftnode;
    root->right=rightnode;
    return root;
}
// TAKE INPUT LEVEL WISE
Node* levelWiseInput(){
    int rootdata;
    cin >> rootdata;
    Node* root = new Node(rootdata);
    queue<Node*>q;
    q.push(root);
    while(q.empty()==false){
        Node* frontNode = q.front();
        q.pop();
        int leftdata;
        cin >> leftdata;
        if(leftdata!=-1){
            Node*leftnode = new Node(leftdata);
            frontNode->left=leftnode;
            q.push(leftnode);
        }
        int rightdata;
        cin >> rightdata;
        if(rightdata!=-1){
            Node*rightnode = new Node(rightdata);
            frontNode->right=rightnode;
            q.push(rightnode);
        }
    }
    return root;
}
// PREORDER TRAVERSAL
void preorderfunction(Node* root,vector<int>&ans){
    if(root==NULL){
        return;
    }
    ans.push_back(root->data);
    preorderfunction(root->left,ans);
    preorderfunction(root->right,ans);
}
vector<int>preorder(Node*root){
    vector<int>ans;
    preorderfunction(root,ans);
    return ans;
}
// POST ORDER TRAVERSAL
void postorderfunction(Node* root,vector<int>&ans){
    if(root==NULL){
        return;
    }
    postorderfunction(root->left,ans);
    postorderfunction(root->right,ans);
    ans.push_back(root->data);
}
vector<int>postorder(Node*root){
    vector<int>ans;
    postorderfunction(root,ans);
    return ans;
}
// IN ORDER TRAVERSAL 
void inorderfunction(Node*root,vector<int>&ans){
    if(root==NULL){
        return;
    }
    inorderfunction(root->left,ans);
    ans.push_back(root->data);
    inorderfunction(root->right,ans);
}
vector<int>inorder(Node*root){
    vector<int>ans;
    inorderfunction(root,ans);
    return ans;
}
// LEVEL ORDER TRAERSAL
vector<vector<int>>levelorder(Node*root){
    vector<vector<int>>ans;
    queue<Node*>q;
    q.push(root);
    while(q.empty()==false){
        int n=q.size();
        vector<int>level;
        for(int i=0;i<n;i++){
            Node*frontnode=q.front();
            q.pop();
            if(frontnode->left!=NULL){
                q.push(frontnode->left);
            }
            if(frontnode->right!=NULL){
                q.push(frontnode->right);
            }
            level.push_back(frontnode->data);
        }
        ans.push_back(level);
    }
    return ans;
}
// COUNT THE NUMBER OF NODES IN BINARY TREE 
int countnodes(Node* root){
    if(root==NULL){
        return 0;
    }
    return countnodes(root->left)+countnodes(root->right)+1;
}
// MAX DEPTH IN BINARY TREE 
int maxDepth(Node* root){
    if(root==NULL){
        return 0;
    }
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return max(leftDepth,rightDepth)+1;
}
// FIND THE MINIMUM VALUE IN BINARY TREE 
int findmin(Node*root){
    if(root==NULL){
        return INT_MAX;
    }
    int ans=root->data;
    int leftmin = findmin(root->left);
    int rightmin = findmin(root->right);
    ans=min(ans,min(leftmin,rightmin));
    return ans;
}
// FIND THE MAXIMUM VALUE IN BINARY TREE 
int findmax(Node*root){
    if(root==NULL){
        return INT_MIN;
    }
    int ans=root->data;
    int leftmax = findmax(root->left);
    int rightmax = findmax(root->right);
    ans=max(ans,max(leftmax,rightmax));
    return ans;
}
// DIAMETER OF BINARY TREE 
int height(int&diameter,Node*root){
    if(root==NULL){
        return 0;
    }
    int leftheight = height(diameter,root->left);
    int rightheigth = height(diameter,root->right);
    diameter = max(diameter,leftheight+rightheigth);
    return 1+max(leftheight,rightheigth);
}
int diameter(Node*root){
    int diameter = 0;
    height(diameter,root);
    return diameter+1;
}
// FIND THE SUM TOTAL OF ALL NODES IN BINARY TREE
int sumfunction(Node*root,int &sum){
    if(root==NULL){
        return 0;
    }
    sum+=root->data;
    sumfunction(root->left,sum);
    sumfunction(root->right,sum);
}
int findSum(Node*root){
    int sum=0;
    sumfunction(root,sum);
    return sum;
}
// CHECK IF TWO BINARY TREES ARE SAME OR NOT 
bool checkfunction(Node* root1,Node* root2){
    if(root1==NULL && root2==NULL){
        return true;
    }
    if(root1==NULL && root2!=NULL){
        return false;
    }
    if(root1!=NULL && root2==NULL){
        return false;
    }
    if(root1->data != root2->data){
        return false;
    }
    return checkfunction(root1->left,root2->left) || checkfunction(root1->right,root2->right); 

}
bool isSame(Node* root1,Node* root2){
    return checkfunction(root1,root2);
}
// MIRROR A BINARY TREE 
void mirror(Node*root){
    if(root==NULL){
        return;
    }
    Node*temp = root->right;
    root->right=root->left;
    root->left=temp;
    mirror(root->left);
    mirror(root->right);
}
// CLONE A BINARY TREE
Node* cloneTree(Node* root){
    if(root==NULL){
        return NULL;
    }
    Node*newNode = new Node(root->data);
    newNode->left=cloneTree(root->left);
    newNode->right=cloneTree(root->right);
}
// CHECK IF THE GIVEN BINARY TREE IS BALANCED 
int height(Node*root,bool &valid){
    if(root==NULL){
        return 0;
    }
    int left =height(root->left,valid);
    int right =height(root->right,valid);
    int diff= abs(left-right);
    if(diff>1){
        valid=false;
    }
    return 1+max(left,right);
}
bool isBalanced(Node*root){
    bool valid = true;
    height(root,valid);
    return valid;
}
// SPIRAL LEVEL ORDER TRAVESRAL
// one way we can solve this is by creating the level order traversal and then reverseing every alternate 
// traversl in the 2D array 
vector<int>findSpiralOrder(Node*root){
    vector<int>ans;
    if(root==NULL){
        return ans;
    }
    stack<Node*>st1;
    stack<Node*>st2;
    st1.push(root);
    while(st1.empty()==false || st2.empty()==false){
        while(st1.empty()==false){
            Node*temp=st1.top();
            st1.pop();
            ans.push_back(temp->data);
            if(temp->right!=NULL){
                st2.push(temp->right);
            }
            if(temp->left!=NULL){
                st2.push(temp->left);
            }
        }
        while(st2.empty()==false){
            Node*temp=st2.top();
            st2.pop();
            ans.push_back(temp->data);
            if(temp->left!=NULL){
                st1.push(temp->left);
            }
            if(temp->right!=NULL){
                st2.push(temp->right);
            }
        }
    }
    return ans;
}
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