#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class node{
public:
int data;
node* next;
node(int val){
    data=val;
    next=NULL;
}
};
void insertion(node* &head,int val){
    node* n=new node(val);
    
    if(head==NULL){
        head=n;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;

}
void display(node*head){
        node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
        
    }
    cout<<"NULL";
    cout<<endl;
    }
node* reverse(node* head){
    node* current=head;
    node* pre=NULL;
    node*nextptr;
    while(current!=NULL){
        nextptr=current->next;
        current->next=pre;

        pre=current;
        current=nextptr;
    }
    return pre;
}

int main (){
node* head=NULL;
insertion(head,1);
insertion(head,2);
insertion(head,3);
insertion(head,4);
display(head);
 node* newhead=reverse(head);
 display(head);
    return 0;
}