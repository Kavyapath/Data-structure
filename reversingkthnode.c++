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



node *getListAfterReverseOperation(node *head, int k){
	// Write your code here.

	int count=0;
	node *curr=head;
	node *pre=NULL;
	node *nxt;
        while (curr!= NULL && count<k) {
			nxt=curr->next;
			curr->next=pre;
			pre=curr;
			curr=nxt;
			count++;

        }
        if(nxt!=NULL){
		head->next=getListAfterReverseOperation(nxt,k);}
        return pre;
}

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

int main(){
    node* head1=NULL;
    node* head2=NULL;
    
    
int arr[]={2,3,3};
insertion(head1,3);
insertion(head1,6);
insertion(head1,9);
insertion(head1,15);
insertion(head1,30);
insertion(head1,32);
display(head1);
head2=getListAfterReverseOperation(head1,3);
display(head2);
return 0;
}

