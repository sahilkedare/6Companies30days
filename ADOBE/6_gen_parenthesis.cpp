// LINK : https://practice.geeksforgeeks.org/problems/generate-all-possible-parentheses/1/#

 void solve(int open,int close,vector<string>&ans,string s){
        if(open==0 and close ==0) {
            ans.push_back(s);
            return;
        }
        if(open!=0){
            string s1=s;
            s1.push_back('(');
            solve(open-1,close,ans,s1);
        }
        if(close>open){
            string s1=s;
            s1.push_back(')');
            solve(open,close-1,ans,s1);
        }
    }
    vector<string> AllParenthesis(int n) 
    {
        vector<string>ans;
        
        solve(n,n,ans,"");
        return ans;
    }