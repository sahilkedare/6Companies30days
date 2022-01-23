// LINK : https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
bool found(vector<int>& weights, int days,int mid){
        int wt=0;
        int d=1;
        for(int i=0;i<weights.size();i++){
            wt+=weights[i];
            if(wt>mid){
                d++;
                wt=weights[i];
            }
            if(d>days){
                return false;
            }
        }
        return true;
    }
    
    int shipWithinDays(vector<int>& w, int days) {
        int n=w.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=w[i];
        }
        int res=-1;
        int low=*max_element(w.begin(),w.end()),high=sum;
        while(low<=high){
            int mid=low + (high-low)/2;
            if(found(w,days,mid)){
                res=mid;
                // cout<<res<<endl;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return res;
    }
