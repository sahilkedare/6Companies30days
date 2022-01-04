// LINK : https://practice.geeksforgeeks.org/problems/ugly-numbers2254/1/#

#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	ull getNthUglyNo(int n) {
	    set<long long>s;
	    long long a;
	    s.insert(1);
	    while(n--){
	        auto it = s.begin();
	        a=*it;
	        s.erase(it);
	        s.insert(a*2);
	        s.insert(a*3);
	        s.insert(a*5);
	    }
	    return a;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.getNthUglyNo(n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends