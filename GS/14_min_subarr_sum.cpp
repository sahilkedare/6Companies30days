// LINK : https://leetcode.com/problems/minimum-size-subarray-sum/solution/

class Solution {
public:
    int minSubArrayLen(int t, vector<int>& nums) {
        int n=nums.size(),sum=0,end=0,start=0,ans=INT_MAX,total=0;
        while(end<n){
            total+=nums[end];
            sum+=nums[end];
            if(sum>=t) {
                while(sum>=t){
                    ans=min(ans,end-start+1);
                    sum-=nums[start++];
                }
            }
            end++;
        }
        if(total<t) return 0;
        return ans;
    }
};