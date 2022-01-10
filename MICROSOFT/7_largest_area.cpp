// LINK : https://practice.geeksforgeeks.org/problems/length-of-largest-region-of-1s-1587115620/1/#

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    void solve(vector<vector<int>>& grid,int i,int j,int n,int m,int &ans){
        if(i>=n or j>=m or i<0 or j<0 or grid[i][j]!=1) return;
        
        grid[i][j]=2;
        ans++;
        solve(grid,i,j+1,n,m,ans);
        solve(grid,i+1,j,n,m,ans);
        solve(grid,i-1,j,n,m,ans);
        solve(grid,i,j-1,n,m,ans);
        solve(grid,i-1,j-1,n,m,ans);
        solve(grid,i+1,j+1,n,m,ans);
        solve(grid,i-1,j+1,n,m,ans);
        solve(grid,i+1,j-1,n,m,ans);
    }
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid){ 
        int n=grid.size();
        int m=grid[0].size();
        int ans=0,res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    ans=0;
                    solve(grid,i,j,n,m,ans);
                    res=max(res,ans);
                }
            }   
        }
        return res;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends