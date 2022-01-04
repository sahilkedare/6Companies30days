// Count the subarrays having product less than k
https://practice.geeksforgeeks.org/problems/count-the-subarrays-having-product-less-than-k1708/1/


// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        long long p=1,c=0;
        for (int start = 0, end = 0; end < n; end++) {
            p*=a[end];
            while(p>=k and start<end) p/= a[start++];
            if(p<k){
                c+=((end-start)+1);
            }
        }
        return c;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends