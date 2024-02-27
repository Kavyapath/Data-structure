#include <bits/stdc++.h> 
using namespace std;
 struct compare {
    bool operator()(pair<int, int> p1, pair<int, int> p2)
    {
        // If frequencies of two elements are same
        // then the larger number should come first
        if (p1.second == p2.second)
            return p1.first < p2.first;
 
        // Insert elements in the priority queue on the
        // basis of decreasing order of frequencies
        return p1.second < p2.second;
    }
};
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    // Write your code here.
    unordered_map<int,int> mp;
    vector<int> ans;
  
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }
      priority_queue<pair<int, int>,vector<pair<int, int>>,compare> pq(mp.begin(),mp.end());
    
    while(k--){
         pair<int,int> t=pq.top();
         ans.push_back(t.first);
         
         
        
        pq.pop();
    }
return ans;
}