#include <bits/stdc++.h>
using namespace std;
#define vl vector<long>

int main() {
	short t;
	cin>>t;
	while(t--){
	    short n;
	    cin>>n;
	    vl a(n);
	    for(auto &i:a){
	        cin>>i;
	    }
	    vl b(n-1);
	    for(auto &i:b){
	        cin>>i;
	    }
	    
	    
	    sort(b.begin(),b.end());
        if(n==2){
            int n=b[0]-a[0];
            int m=b[0]-a[1];
            cout<<abs(min(n,m))<<endl;//to convert all negative sign to postive we can use function abs() for integer ans fabs() for float and dabs() for double

        }
       else{
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int x=b[n-2]-a[i];
                int y=b[n-3]-a[j];
                if(x==y){
                    cout<<y<<endl;

                }

            }
        }}
	}
	return 0;
}
