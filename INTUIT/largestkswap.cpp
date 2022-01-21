// LINK: https://practice.geeksforgeeks.org/problems/largest-number-in-k-swaps-1587115620/1#

void solve(string str, string &max, int k, int pos){
        if(k==0) return;
        char maxm=str[pos];
        for(int i = pos+1; i < str.length() ;i++){
            if(maxm < str[i])
                maxm = str[i];
        }
         if(maxm != str[pos])
            k--;
        
        for(int i=str.length()-1; i>=pos ;i--)
        {
            if(str[i] == maxm)
            {
                swap(str[i], str[pos]);
                if(str.compare(max) > 0)
                    max = str;
                    
                solve(str, max, k, pos+1);
                
                swap(str[i], str[pos]);
            }
        }
    }
    string findMaximumNum(string str, int k)
    {
        int n=str.size();
        int i=0,j=n-1;
        string max=str;
        solve(str,max,k,0);
        return max;

    }