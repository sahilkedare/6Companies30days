    // LINK : https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1            

int equalPartition(int n, int a[]){
    int sum=0;
    for(int i=0;i<n;i++) sum+=a[i];
    if(sum%2==0){
        int s=sum/2;
        bool dp[n+1][s+1];
        for(int i=1;i<=sum;i++){
            dp[0][i] = 0;
        }
        for(int i=0;i<=n;i++){
            dp[i][0] = 1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=s;j++){
                if(a[i-1]<=j) dp[i][j]=dp[i-1][j-a[i-1]] || dp[i-1][j] ;
                else  dp[i][j]=dp[i-1][j];
                    
            }
        }
        return dp[n][s];
    }
    else {
        return 0;
    }
}