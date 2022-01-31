https://practice.geeksforgeeks.org/problems/sorted-subsequence-of-size-3/1/

vector<int> find3Numbers(vector<int> arr, int N) {
         int mn=arr[0];
         int mx=INT_MAX;
         int s=arr[0];
         vector<int>ans;
         for(int i=1;i<N;i++){
             if(arr[i]==mn) continue;
             else if(arr[i]<mn) mn=arr[i];
             else if(arr[i]<mx) mx=arr[i],s=mn;
             else if(arr[i]>mx){
                 ans.push_back(s);
                 ans.push_back(mx);
                 ans.push_back(arr[i]);
                break;
             }
         }
         return ans;
    }