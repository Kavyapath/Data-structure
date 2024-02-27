#include <iostream>
#include<bits/stdc++.h>
using namespace std;

struct node{
int data;
node *left, *right;
node(int x){
    data=x;
    left=NULL;
    right=NULL;
}
};

bool isbst(node* root,node*min=NULL,node*max=NULL){
    if(root==NULL){
        return true;
    }
    if(min!=NULL && root->data<=min->data){
        return false;

    }
    if(max!=NULL && root->data>=max->data){
        return false;
    }
    
    bool leftvalid=isbst(root->left,min,root);
    bool rightvalid=isbst(root->right,root,max);
    return leftvalid and rightvalid;


}
void inorder(node* root){
    if(root!=NULL){
    inorder(root->left);
    cout<<root->data;
    inorder(root->right);
 
}}           

node* insertion(node* root,int x){
    if(root==NULL){
        return new node(x);

    }
    else if(x<root->data){
        root->left=insertion(root->left,x);
    }
    else{
        root->right=insertion(root->right,x);
    }
}

node* inordersucc(node*root){//succer means in rigth side of tree find the left most minimum node replace it with the deleting node
    node*tem=root;
    while(tem && tem->left!=NULL){
tem=tem->left;
    }
    return tem;
    
}


node *deletenode(node* root, int key){


    if(key<root->data){
        root->left=deletenode(root->left,key);
    }
    if(key>root->data){
        root->right=deletenode(root->right,key);
    }
    else{
        if(root->left==NULL){
                // at here the root node is deleted and instead of it we will return the right nod eof the previous root hence our root is deleted and the new node which will take its place in bst returning us
            node* temp=root->right;
            delete(root);
            return temp;
        }
        if(root->right==NULL){
                // at here the root node is deleted and instead of it we will return the left node of the previous root hence our root is deleted and the new node which will take its place in bst returning us
            node* temp=root->left;
            delete(root);
            return temp;
        }
        if(root->right==NULL && root->left==NULL){
            delete(root);
            return NULL;
        }
        else{
            node*temp=inordersucc(root->right);
            root->data=temp->data;
            root->right=deletenode(root->right,temp->data);

        }
    }
    return root;

}

int main(){

    node* root=new node(6);
    root->left=new node(4);
    root->right=new node(7);
    node* p=new node(3);
    node* q=new node(5);
    root->left->left=p;
    root->left->right=q;


    if(isbst(root,NULL,NULL)){
        cout<<"is bst"<<endl;

    }
    else{
        cout<<"no"<<endl;
    }
    insertion(root,2);
    insertion(root,8);
    insertion(root,10);
    
    


     cout<<"insertion is"<<endl;
     inorder(root);


    cout<<endl;


    node*n=deletenode(root,4);
     cout<<"deletion is"<<endl;


    inorder(root);
        cout<<endl;
        cout<<"new root is"<<n->data<<endl;
}