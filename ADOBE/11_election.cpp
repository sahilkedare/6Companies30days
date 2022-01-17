// LINK : https://practice.geeksforgeeks.org/problems/winner-of-an-election-where-votes-are-represented-as-candidate-names-1587115621/1/#

 //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[],int n)
    {
        map<string,int>mp;
        string s="";
        int mx=0;
        vector<string>v;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        for (auto i : mp){
            // cout<<i.first<<i.second<<endl;
            if(i.second>mx){
                mx=i.second;
                s=i.first;
            }
        }
            v.push_back(s);
            v.push_back(to_string(mx));
        return v;
    }