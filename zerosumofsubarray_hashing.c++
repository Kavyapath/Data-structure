#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
cin>>n;
vector<int> v(n);
for(auto &i:v){
    cin>>i;
}
int ans=0;
int prefsum=0;
map<int,int> m;
for(int i=0;i<n;i++){
    prefsum+=v[i];
    m[prefsum]++;
}
for(auto it=m.begin();it!=m.end();it++){
int c=it->second;
ans+=c*(c-1)/2;//learn formulaa for gettting two or more subarray for example [1,-1,1,-1]
if(it->first==0){
    ans+=it->second;
}

}
cout<<ans<<endl;
return 0;

}
