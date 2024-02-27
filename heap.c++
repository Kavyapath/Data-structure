#include<bits/stdc++.h>

using namespace std;


//heap using array

class Minheap{

public:


int *harr;
int capacity;
int size;



Minheap(int cap)
{
    size=0;
    capacity=cap;
    harr=new int[cap];
}
int linear_search(int val){
    for(int i=0;i<size;i++){
        if(harr[i]==val){
            cout<<"value find is"<<val<<endl;
            return i;
        }
        else{
            cout<<"not found"<<endl;
            return-1;
        }
    }

}

void printarr(){
    for(int i=0;i<size;i++){
        cout<<harr[i]<<" ";
        cout<<endl;
    }
}
int height(){
    return ceil(log2(size+1))-1;
}

int parent(int i){
    return (i-1)/2;
}
int left_child(int i){
    return (2*i)+1;
}
int right_child(int i){
    return (2*i)+2;
}
void insert(int k){

    if(size==capacity){
        cout<<"\n overflow : could not insert";
        return;
    }
    size++;
    int i=size-1;
    harr[i]=k;

    while(i!=0 && harr[parent(i)]>harr[i]){

        swap(harr[i],harr[parent(i)]);
        i=parent(i);
    }
    

}

 void minheapfy(int i){

    int l,r,s;
    l=left_child(i);
    r=right_child(i);
    s=i;
    if(l<size && harr[l] < harr[s]){
        s=l;
    }
    if(r<size && harr[r] < harr[s]){
        s=r;
    }
    if(s!=i){
        swap(harr[i],harr[s]);
        minheapfy(s);
    }
    
 }

 int extractmin(){
    if(size<=0){
        return 0;
    }
    if(size==1){
         size--;
         return harr[0];
    }
    int root=harr[0];
    harr[0]=harr[size-1];
    size--;
    minheapfy(0);
    return root;
 }
 int delete_ele(int index){
 int value=harr[index];
 harr[index]=harr[size-1];
 size--;
 minheapfy(index);
 return value;

 }
};
int main(){
    int s,n,element;
    cout<<"enter the size of heap"<<endl;
    cin>>s;
    Minheap obj(s);
cout<<"insert the element"<<endl;
cout<<"enter the no of element you wanted to insert"<<endl;
cin>>n;
while(n--){
    cout<<"enter the element"<<endl;
    cin>>element;
 obj.insert(element);
}
cout<<endl;
obj.printarr();


cout<<endl;

int index;
cout<<"enter the index value to be deleted"<<endl;
cin>>index;

cout<<"key deleted at index value is :"<<obj.delete_ele(index)<<endl;
obj.printarr();
    return 0;
}