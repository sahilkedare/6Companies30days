LINK : https://docs.google.com/document/d/18oi6OlvcL3wYn20Jb9crW7NO4cGkL6vUfTvplNDGkTw/edit

vector<vector<int>>adj;
vector<bool>vis;
    
int get_comp(int idx) {
    if(vis[idx])
        return 0;
    
    vis[idx] = true;
    int ans=1;
    for(auto i: adj[idx]){
        if(!vis[i]){
            ans+= get_comp(i);
            vis[i]=true;
        }
    }
    return ans;
}
    
    int findCircleNum(vector<vector<int>>& c) {
        int n=c.size();
        adj=vector<vector<int>>(n);
        vis=vector<bool>(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(c[i][j]==1 and i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int count=0;
        for(int i=0; i<n;i++){
            if(!vis[i]){
                get_comp(i);
                count++; 
                cout<<"F";
            }
        }
        return count;            
    }