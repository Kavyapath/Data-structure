#include <bits/stdc++.h> 

using namespace std;
#define vvi vector<vector<int>>

bool findTargetInMatrix(vector < vector < int >> & mat, int m, int n, int target) {
    // Write your code here.
    bool flag=false;
    for(int i=0;i<m;i++){
      for (int j=0;j<n;j++){
          if(mat[i][j]==target){
              flag=true;
              break;
          }

      }
    }
    return flag;
}
int main(){
short t;
cin>>t;
int m,n,tar;
cin>>m>>n>>tar;
vvi arr(m,vector<int>(n));
for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        cin>>arr[i][j];
    }
}
bool res=findTargetInMatrix(arr,m,n,tar);
if(res==true){
cout<<"true"<<endl;}
else{
    cout<<"false"<<endl;
}

    return 0;
}