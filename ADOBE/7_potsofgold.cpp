// LINK : https://practice.geeksforgeeks.org/problems/pots-of-gold-game/1/#

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

    int maxCoins(vector<int>&A,int n)
    {
        memset(dp,0, sizeof dp);
	    return findMaxCoins(A,0,n-1);
    }