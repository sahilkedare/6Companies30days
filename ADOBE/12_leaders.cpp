// LINK : https://practice.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1/

vector<int> leaders(int a[], int n){
        vector<int>ans;
        int mx=a[n-1];
        ans.push_back(a[n-1]);
        for(int i=n-2;i>=0;i--){
            if(a[i]>=mx){
                ans.push_back(a[i]);
                mx=a[i];
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }