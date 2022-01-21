// LINK :  https://leetcode.com/problems/koko-eating-bananas/

bool found(int mid,vector<int>& piles, int h) {
        int c=0;
        for(int i=0;i<piles.size();i++){
            c+=ceil((1.0*piles[i]/mid));
        }
        if(c<=h) return true;
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        sort(piles.begin(),piles.end());
        int high=*max_element(piles.begin(),piles.end());
        int ans=-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(found(mid,piles,h)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};