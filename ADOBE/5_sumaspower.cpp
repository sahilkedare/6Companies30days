LINK : https://practice.geeksforgeeks.org/problems/express-as-sum-of-power-of-natural-numbers5647/1#

 int dp[1001][1001];
    int solve(int i,int sum,int limit,int x,int n){
        if(i>limit+1){
            return 0;
        }
        else if(sum>n) return 0;
        else if(dp[i][sum]!=-1) return dp[i][sum];
        else if(sum==n) return 1;
    
        int withpowsum=solve(i+1,sum+pow(i,x),limit,x,n);
        int withoutpowsum=solve(i+1,sum,limit,x,n);
        return dp[i][sum]=withpowsum + withoutpowsum;

    }
    int numOfWays(int n, int x){
        int limit= pow(n,1.0/x);
        memset(dp,-1,sizeof(dp));
        return solve(1,0,limit,x,n);
       
    }