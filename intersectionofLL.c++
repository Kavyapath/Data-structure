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
    cout<<"NULL"<<endl;
    }
node* reverse(node* head){
    node* current=head;
    node* pre=NULL;
    node*nextptr=current->next;
    while(current!=NULL){
        nextptr=current->next;
        current->next=pre;

        pre=current;
        current=nextptr;
    }
    return pre;
}
int size(node* head){
    node* temp=head;
    int l=0;
    while(temp!=NULL){
         l++;
        temp=temp->next;
        
    }
    return l;
}

void intersect(node* head1,node* head2,int k){
     node* temp=head1;
     
     while(k--){
        temp=temp->next;
     }
     node* temp2=head2;
     while(temp2->next=NULL){
        temp2=temp2->next;
        

     }
     temp2->next=temp;
}
int intersectionPoint(node* head1,node* head2){
int l1=size(head1);
int l2=size(head2);
int d=0;
node* ptr1;
node* ptr2;
if(l1>l2){
    d=l1-l2;
    ptr1=head1;
    ptr2=head2;
}
else{
    d=l2-l1;
    ptr1=head2;
    ptr2=head1;
}
while(d--){
    
    ptr1=ptr1->next;
    if(ptr1==NULL){
        return -1;}
}
while(ptr1!=NULL&&ptr2!=NULL){
     if(ptr1==ptr2){
        return ptr1->data;
    }
    ptr1=ptr1->next;
    ptr2=ptr2->next;


}
return 1;

}

int main (){
node* head1=NULL;
node* head2=NULL;
insertion(head1,3);
insertion(head1,6);
insertion(head1,9);
insertion(head1,15);
insertion(head1,30);
//insertion(head1,6);
insertion(head2,11);
insertion(head2,10);

display(head2);
intersect(head1,head2,2);
display(head1);
display(head2);
cout<<intersectionPoint(head1,head2)<<endl;


    return 0;
}