// LINK : https://practice.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem3257/1#s

 bool canPair(vector<int> nums, int k) {
        map<int,int>mp;
        for(auto x:nums) mp[x%k]++;
        // for(auto x:mp) cout<<x.first<<" "<<x.second<<endl;
        if(mp[0]%2!=0) return false;
        
        for(int i=1;i<k;i++){
            if(mp[i]!=mp[k-i]) return false;
        }
        return true;
    }
