// https://leetcode.com/problems/stone-game

class Solution {
public:
    int dp[501][501];
    int findMaxCoins(vector<int>&coin, int i, int j){
        if (i == j) {
            return coin[i];
        }
    
        if (i + 1 == j) {
            return max(coin[i], coin[j]);
        }
        if(dp[i][j]==0){
            int start = coin[i] + min(findMaxCoins(coin, i + 2, j),
                                    findMaxCoins(coin, i + 1, j - 1));
         
            int end = coin[j] + min(findMaxCoins(coin, i + 1, j - 1),
                            findMaxCoins(coin, i, j - 2));
            dp[i][j]=max(start,end);
        }
        return dp[i][j];
    }
    bool stoneGame(vector<int>& piles) {
        int sum=0;
        int n=piles.size();
        for(int i=0;i<n;i++) sum+=piles[i];
        memset(dp,0, sizeof dp);
	    int x= findMaxCoins(piles,0,n-1);
        int y=sum-x;
        return x>y;
        
    }
};