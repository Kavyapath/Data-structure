#include<bits/stdc++.h>

using namespace std;
int a[100005],seg[4*100005],lazy[4*100005];
void build(int ind,int low,int high){
    //this is our base case if low get equals to high means (1,1) or (2,2)
    if(low==high){
seg[ind]=a[low];
return ;
    }
    //now traverse in left and right half in binary fashion using recursion
    int mid=(low+high)>>1;
    build(2*ind+1,low,mid);
    build(2*ind+2,mid+1,high);
    //and in the backtracking step we will evaluate the maximum for the right and the left half
    seg[ind]=max(seg[2*ind+1],seg[2*ind+2]);//
}
int query(int ind,int low,int high,int l,int r){
    //write the completely laying in the domain condition
    if(l<=low && high<=r){
return seg[ind];//maximum element of that child tree

    }

    if(l>high || r<low){
        return INT_MIN;
    }
    //it overlapping the domain
    int mid=(low + high)>>1;
    int left=query(2*ind+1,low,mid,l,r);
    int right=query(2*ind+2,mid+1,high, l,r);

    return max(left,right);
}
void RangeUpdate(int ind,int low,int high,int l,int r,int val){//with lazy propogation
    if(lazy[ind]){
        seg[ind]+=(high-low+1)*val;
        if(low!=high){
            lazy[2*ind+1]+=val;
            lazy[2*ind+2]+=val;
        }
        lazy[ind]=0;

    }
    if(low>r || high<l ||low>high){//not lie inth e domain

        return;
    }
    else if(low>=l && high<=r){
        seg[ind]=(high-low+1)*lazy[ind];
        if(low!=high){//means not a leaf node
        lazy[2*ind+1]+=lazy[ind];
         lazy[2*ind+2]+=lazy[ind];

        }
        return ;
    }
    int mid=(high+low)>>1;
    RangeUpdate(2*ind+1,low,mid,l,r,val);
     RangeUpdate(2*ind+2,mid+1,high,l,r,val);
     seg[ind]=seg[2*ind+1]+seg[2*ind+2];


}
int querySumLazy(int ind,int low,int high,int l,int r,int val){

      if(lazy[ind]){
        seg[ind]+=(high-low+1)*val;
        if(low!=high){
            lazy[2*ind+1]+=val;
            lazy[2*ind+2]+=val;
        }
        lazy[ind]=0;

    }
    //write the completely laying in the domain condition
    if(l<=low && high<=r){
return seg[ind];//maximum element of that child tree

    }

    if(l>high || r<low){
        return 0;
    }
    //it overlapping the domain
    int mid=(low + high)>>1;
    int left=query(2*ind+1,low,mid,l,r);
    int right=query(2*ind+2,mid+1,high, l,r);

    return left+right;
}

int main(){
int n;
cin>>n;
for(int i=0;i<n;i++)
{
    cin>>a[i];
}
build(0,0,n-1);//first parameter we will start building segmet tree from the root node(starting index which is at i and its child will be at 2*i+1,2*i+2) so it is 0
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<query(0,0,n-1,l,r)<<endl;
    }
    
    return 0;
}

