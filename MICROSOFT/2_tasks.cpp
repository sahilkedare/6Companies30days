// LINK : https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1/#

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
        
	bool isPossible(int N, vector<pair<int, int> >& pre) {
	    vector<int>adj[N];
	    for(int i=0; i<pre.size(); i++){
	        int u = pre[i].first, v = pre[i].second;
	        adj[u].push_back(v);
	    }
	    int cnt = 0;
	    vector<int> indeg(N, 0);
	    for(int i=0; i<N; i++) {
	        for(auto& it: adj[i]) {
	            indeg[it]++;
	        }
	    }
	    
	    queue<int> q;
	    for(int i=0; i<N; i++) {
	        if(indeg[i]==0) q.push(i);
	    }
	    while(!q.empty()) {
	        int node = q.front();
	        q.pop();
	        cnt++;
	        for(auto& it: adj[node]) {
	            indeg[it]--;
	            if(indeg[it]==0) q.push(it);
	        }
	    }
	    return (cnt==N);
	}
};