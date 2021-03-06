// LINK : https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1

vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        int i=0,j=0;
        priority_queue<pair<int,int>>pq;
        vector<int>ans;
        while(j<n){
            if(j-i+1<k){
                pq.push({arr[j],j});
                j++;
            }
            else{
                pq.push({arr[j],j});
                ans.push_back(pq.top().first);
                while(!pq.empty()){
                    if(pq.top().second<=i) pq.pop();
                    else break;
                }
                i++;
                j++;
            }
        }
        return ans;