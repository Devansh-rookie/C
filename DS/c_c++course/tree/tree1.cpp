#include<iostream>
#include<queue>
using namespace std;

class node{
    public:// like the struct part of C
        int val;
        node * left;
        node * right;

    node(int val){// like the __init__ method of python
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

node * buildTree(node * root){
    int val;
    cout<<"Enter the Value: "<<endl;
    cin>>val;
    root = new node(val);

    if(val== -1) return NULL;

    cout<<"For Left of "<<val<<endl;
    (root)->left = buildTree(root->left);
    cout<<"For Right of "<<val<<endl;
    (root)->right = buildTree(root->right);
    return root;
}

void levelOrderTraversal(node * root){
    // also called breadth first traversal
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node * temp = q.front();
        // cout<<temp->val<<" ";// otherwise its giving segmentation fault

        q.pop();

        q.push(NULL); // its like adding a \n in there use NULL there and whenever we complete any level like after root level 0 is completed then use NULL then after level 1 and level 2 and so on
        if(temp == NULL){
            cout<< endl;
            if(!q.empty()){
                // as now q still has child nodes
                q.push(NULL);
            }
        }
        else{
            cout<<temp->val<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

int main(){
    node * root= NULL;

    root = buildTree(root);
    // 1 2 -1 -1 3 -1 -1
    levelOrderTraversal(root);

    return 0;
}
