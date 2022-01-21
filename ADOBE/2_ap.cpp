// # LINK : https://practice.geeksforgeeks.org/problems/longest-arithmetic-progression1019/1/

int lengthOfLongestAP(int set[], int n) {
        if (n <= 2)  return n;
        int L[n][n];
        int llap = 2;  // Initialize the result
    
        for (int i = 0; i < n; i++)
            L[i][n-1] = 2;
        
        for (int j=n-2; j>=1; j--) {
            // Search for i and k for j
            int i = j-1, k = j+1;
            while (i >= 0 && k <= n-1) {
                if (set[i] + set[k] < 2*set[j]) k++;
               // Before changing i, set L[i][j] as 2
                else if (set[i] + set[k] > 2*set[j])
                {   L[i][j] = 2, i--;   }
    
                else{
                    L[i][j] = L[j][k] + 1;
                           // Update overall LLAP, if needed
                    llap = max(llap, L[i][j]);
        // Change i and k to fill more L[i][j] values for current j
                   i--; k++;
                }
            }
            // If the loop was stopped due to k becoming more than
                    // n-1, set the remaining entities in column j as 2
            while (i >= 0){
                L[i][j] = 2;
                i--;                }
        }
        return llap;
    }