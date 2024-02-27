#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> v;
	    unordered_set<int> s;
	    
	    for(int i=0;i<n;i++){
	        cin>>v[i];
	    }
	    for(auto it:v){
	        s.insert(it);
	    }
	    cout<<s.size()<<endl;
	}
	return 0;
}
