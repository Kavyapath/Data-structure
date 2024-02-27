#include<bits/stdc++.h>
#define vi vector<int> 
using namespace std;

int main(){
    short n,k;
cin>>n>>k;
 vi a(n);
 for(auto &i:a){
    cin>>i;
 }
 int s=0,ans=INT_MAX;
 for(int i=0;i<k;i++){
    s+=a[i];

 }
 cout<<s<<" ";//value of s is printed for the first k windows the we run another loop for sliding the windows and compute the values of s
 ans=min(ans,s);
 for(int i=1;i<n-k+1;i++){
    s-=a[i-1];
    s+=a[i+k-1];
    ans=min(ans,s);
cout<<s<<"  ";
 }
 cout<<endl;
 cout<<ans<<endl;
    return 0;
}