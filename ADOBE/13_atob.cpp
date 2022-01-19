// LINK : https://practice.geeksforgeeks.org/problems/minimum-insertions-to-make-two-arrays-equal/1/#

int LIS(vector<int> A, int N){
        if(A.empty()) return 0;
        vector<int> tail(N, 0);
        int len = 1; tail[0] = A[0];
        for (int i = 1; i < N; i++) {
            if (A[i] < tail[0]) tail[0] = A[i];
            else if (A[i] > tail[len - 1]) tail[len++] = A[i];
            else {
                int pos = lower_bound(tail.begin(), tail.begin()+len, A[i])-tail.begin();
                tail[pos] = A[i];
            }
        }
        return len;
    }