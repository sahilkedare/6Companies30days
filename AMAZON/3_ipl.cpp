// LINK : https://practice.geeksforgeeks.org/problems/deee0e8cf9910e7219f663c18d6d640ea0b87f87/1/# 

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