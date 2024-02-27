#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int a,b,t;
	cin>>t;
	while(t--){
	    cin>>a>>b;
	    if(a==b){
	        cout<<"yes"<<endl;
	        
	    }
	    else{
	        for(int i=0;i<10;i++){
	            if(a*(2*i)==b){
	                cout<<"yes"<<endl;
                    a=a*(2*i);
	            }
	            else if(b*(2*i)==a){
	                cout<<"yes"<<endl;
	                b=b*(2*i);
	            }
	           
	        }
	    }
        if(a!=b){
            cout<<"no"<<endl;
        }
	}
	return 0;
}
