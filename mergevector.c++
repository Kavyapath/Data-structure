#include <bits/stdc++.h>
using namespace std;
 
int main()
{int n,m;
cin>>n>>m;
    // initializing 1st container
    vector<int> arr1(n+m,0);
 
    // initializing 2nd container
    vector<int> arr2(m,0);
 
    // declaring resultant container
    vector<int> arr3(m+n);
	for(auto &i:arr1){
		cin>>i;

	}
	for(auto &i:arr2){
		cin>>i;

	}
 
    // sorting initial containers
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
 
    // using merge() to merge the initial containers
    merge(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), arr3.begin());
	for (int i = 0; i < arr3.size(); i++)
        cout << arr3[i] << " ";
 
    // printing the resultant merged container
    cout << "The container after merging initial containers is : ";
 
    for (int i = 0; i < arr3.size(); i++)
        cout << arr3[i] << " ";
    return 0;
}