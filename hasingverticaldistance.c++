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
void getvertical_order(node *root,int hd,map<int,vector<int>> &m){
if(root==NULL){
    return;
}
m[hd].push_back(root->data);//here we are entering value in vector that's why we have to use pushback function instead of m[hd]=root->data we can use this when we are working int containers
getvertical_order(root->left,hd-1,m);
getvertical_order(root->right,hd+1,m);

}
int main(){
    
node *root=new node(10);

root->left=new node(7);

root->right=new node(4);
root->left->left=new node(3);

root->left->right=new node(11);
root->right->left=new node(14);
root->right->right=new node(6);
int hd=0;
map<int,vector<int>> m;
getvertical_order(root,hd,m);


for(auto it=m.begin();it!=m.end();it++){
    for(int i=0;i<(it->second).size();i++){
    cout<<it->first<<" -> "<<(it->second)[i]<<"  ";
    
    }
    cout<<endl;
}

    return 0;


}