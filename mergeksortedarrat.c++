#include <bits/stdc++.h> 
using namespace std;
#define ppi pair<int,pair<int,int>>
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
    priority_queue<ppi,vector<ppi>,greater<ppi>> pq;
    vector<int> ans;
    for(int i=0;i<k;i++){
      pq.push({kArrays[i][0],{i,0}});
    }
    while(pq.empty()==false){
        ppi cur=pq.top();
        pq.pop();
        int i=cur.second.first;
        int j=cur.second.second;
        ans.push_back(cur.first);
        if(j+1 < kArrays[i].size()){
            pq.push({kArrays[i][j+1],{i,j+1}});
        }

    }
    return ans;
}
