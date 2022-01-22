// LINK: https://leetcode.com/problems/course-schedule-ii/
 bool dfs(int u, vector<vector<int>>&adj,vector<int>&vis,vector<int>&s){
        vis[u]=1;
        for(int v:adj[u]){
            if(vis[v]==1) return true;
            if(vis[v]==0 and dfs(v,adj,vis,s)) return true;
        }
        vis[u]=2;
        s.push_back(u);
        return false;
    }
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<vector<int>>adj(n);
        for(vector<int>&c: p)
            adj[c[1]].push_back(c[0]);
        
        vector<int>s;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]==0 and dfs(i,adj,vis,s)) return {} ;
        }
        reverse(s.begin(),s.end());
        return s;
    }