#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};
//function to print binary tree
node* buildtree(node* root){
    cout<<"enter the data: "<<endl;
    int data;
    cin>>data;
    root=new node(data);

    if(data==-1) return NULL;
    cout<<"enter data for inserting in left: "<<endl;
    root->left=buildtree(root->left);
    cout<<"enter data for inserting in right: "<<endl;
    root->right=buildtree(root->right);
    return root;
}
void levelordertraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        if(temp==NULL){
            //previous level traversal is completed
            cout<<endl;
            if(!q.empty()) q.push(NULL);
        }
        else{
                    cout<<temp->data<<" ";
            if(temp->left)q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
}
void preorder(node* root){
    if(root ==NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main(){
    node* root=NULL;
    //creating a tree
    root=buildtree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    //level order
    cout<<"level order traversal is: "<<endl;
    levelordertraversal(root);
}
//to print level order traversal in levels we need a separator and that separator is NULL