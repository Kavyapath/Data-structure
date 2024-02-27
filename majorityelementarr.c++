#include <bits/stdc++.h> 
using namespace std;
vector<int> findMajorityElement(int arr[], int n,int k) {
	// Write your code here.
	
map<int,int> m;
vector<int> ans;
for(int i=0;i<n;i++){
	m[arr[i]]++;
}
for(auto it=m.begin();it!=m.end();it++){
	if(it->second>=k){
		 ans.push_back(it->first);
	}
}
return ans;
	
}
int main(){

    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> ans=findMajorityElement(arr,n,2);
    for(auto& i:ans){
        cout<<i<<endl;
    }
    return 0;
}