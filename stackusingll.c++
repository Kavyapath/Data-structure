#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class node{
public:
int data;
node* next;
node*top;

node(int val){
    data=val;
    next=NULL;
    top=NULL;
}
};
int isempty(node* top){
    if(top==NULL){
        return 1;
    }
    return 0;
}
int pop(node* top){
    if(top==NULL){
        cout<<"stack is empty"<<endl;
        return -1;
    }
    else{
        int tempdata=top->data;
        node* temp=top;
        top=top->next;
        delete temp;
        return tempdata;
    }
}
void push(int val,node*top){
    node *n=new node(val);
    if(top==NULL){
        top=n;

    }
    n->next=top;
    top=n;
    cout<<"value pushed into stack "<<val<<endl;
}
int peek(node*top){
    if(top==NULL){
        return -1;
    }
    else{
        return top->data;
    }
}

int main(){
node* top;
push(8,top);
push(3,top);
push(5,top);
//display(top);
while(!isempty(top)){
        
        cout<<peek(top)<<"  ";
        pop(top);

    }
    
    
    
    
    return 0;
}