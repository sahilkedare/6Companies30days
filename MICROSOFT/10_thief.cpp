// LINK : https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1/#

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        if(n==1) return arr[0];
        // if(n==2) return max(arr[0],arr[1]);
        // int dp[n];
        // dp[0]=arr[0];
        // dp[1]=arr[1];
        // dp[2]=max(arr[0]+arr[2],arr[1]);
        // for(int i=3;i<n;i++){
        //     dp[i]=max(dp[i-1],dp[i-2]+arr[i]);
        //     // cout<<dp[i]<<" ";
        // }
        // return max(dp[n-1],dp[n-2]);
        
        int a = 0;
        int b = arr[0];
        
        for(int i=2;i<=n;i++)
        {
            int c = max(b, a+arr[i-1]);
            a = b;
            b = c;
        }
        
        return b;
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}
  // } Driver Code Ends