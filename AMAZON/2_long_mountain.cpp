// LINK : https://leetcode.com/problems/longest-mountain-in-array/submissions/

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n=arr.size();
        vector<int>left(n,1);
        vector<int>right(n,1);
        
        for(int i=1;i<n;i++){
            if(arr[i-1] < arr[i]){
                left[i]=left[i-1]+1;
            }
        }
        
        for(int i=n-1;i>0;i--){
            if(arr[i-1] > arr[i]){
                right[i-1]=right[i]+1;
            }
        }
        int ans=0;
        for(int i=1;i<n-1;i++){
            if(arr[i-1]<arr[i] and arr[i]>arr[i+1]){
                ans=max(ans,left[i-1]+right[i+1]+1);
            }
        }
        // for(int i=0;i<n;i++){
        //     cout<<left[i]<<" ";
        // }
        // cout<<endl;
        // for(int i=0;i<n;i++){
        //     cout<<right[i]<<" ";
        // }
        return ans;
    }
};