#include<bits/stdc++.h>
using namespace std;
const int N=1e3+2, mod = 1e9+7;
int arr[N];

void minsubsetdiff(int n,int sum){
    bool dp[n+1][sum+1];

    for(int i=1;i<=sum;i++){
        dp[0][i] = false;
    }
    for(int i=0;i<=n;i++){
        dp[i][0] = true;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(arr[i-1]>j)
                dp[i][j]= dp[i-1][j];
            if(arr[i-1]<=j) 
                dp[i][j]= dp[i-1][j] || dp[i-1][j-arr[i-1]];
        }
    }

    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            cout<<dp[i][j]<<" ";
       }
       cout<<endl;
    }
    cout<<endl;

    vector<int>v;
    for(int i=0; i<=sum/2; i++){
        if(dp[n][i]){
            v.push_back(i);
        }
    }
    int minn=INT_MAX;
    for(int i=0; i<v.size(); i++){
        minn=min(minn,(sum-(2*v[i])));
    }
    cout<<minn<<endl;
}


int main()
{
    int n;cin >> n;
    // n=5 sum=11
    // 2 3 7 8 10
    int sum=0;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        sum+=arr[i];
    }

    minsubsetdiff(n,sum);
   
	return 0;
}