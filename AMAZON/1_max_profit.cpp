// LINK : https://practice.geeksforgeeks.org/problems/maximum-profit4657/1

int maxProfit(int k, int n, int a[]) {
       int dp[k+1][n];
       memset(dp,0,sizeof(dp));
       for(int i=1;i<=k;i++)
       {
           int mx=INT_MIN;
           for(int j=1;j<n;j++)
           {
               mx=max(mx,dp[i-1][j-1]-a[j-1]);
               dp[i][j]=max(dp[i][j-1],mx+a[j]);
           }
       }
    //   for(int i=0;i<=k;i++)
    //   {
    //       for(int j=0;j<n;j++)
    //       {
    //           cout<<dp[i][j]<<" ";
    //       }
    //       cout<<endl;
    //   }
       return dp[k][n-1];

    }