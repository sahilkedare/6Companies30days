// LINK : https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1#

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
      stack<pair<int,int>>st;
      st.push({price[0],1});
      vector<int>ans(n,1);
      int i=1,c=0;
      while(i<n){
            c=0;
            while(!st.empty() && st.top().first<=price[i]){
                c+=st.top().second;
                st.pop();
            }
            ans[i]+=c;
            st.push({price[i],ans[i]});
            i++;
      }
      return ans;
    }
};



// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
  // } Driver Code Ends