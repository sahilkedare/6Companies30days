// LINK : https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1#

 vector<int> subarraySum(int arr[], int n, long long sum){
        int curr_sum = arr[0], start = 0, i;
        for (i = 1; i <= n; i++) {
            while (curr_sum > sum && start < i - 1) {
                curr_sum = curr_sum - arr[start];
                start++;
            }
            if (curr_sum == sum) {
                vector<int>ans={start+1,i};
                return ans;
            }
            if (i < n)
                curr_sum = curr_sum + arr[i];
        }
        vector<int>ans={-1};
        return ans;
    }