// LINK : https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1            

int l, r;
    sort(A.begin(),A.end());
    vector<vector<int>>myVec;
    int n=A.size();
    for (int i = 0; i < n - 3; i++)
    {
        for (int j = i+1; j < n - 2; j++)
        {
            l = j + 1;
            r = n-1;

            while (l < r)
            {
                if( A[i] + A[j] + A[l] + A[r] == X)
                {
                    myVec.push_back({A[i],A[j],A[l],A[r]});
                    l++; r--;
                }
                else if (A[i] + A[j] + A[l] + A[r] < X)
                    l++;
                else 
                    r--;
            } 
        }
    }
    sort(myVec.begin(), myVec.end());
    myVec.erase(unique(myVec.begin(), myVec.end()), myVec.end());
    return myVec;