// LINK : https://practice.geeksforgeeks.org/problems/amend-the-sentence3235/1

string amendSentence (string s)
    {
        char a=tolower(s[0]);
        string res="",ans="";
        ans+=a;
        for(int i=1;i<s.length();i++){
            if(isupper(s[i])){
                res+=ans;
                res+=" ";
                char c=tolower(s[i]);
                ans="";
                ans+=c;
            }
            else{
                ans+=s[i];
            }
        }
        res+=ans;
        return res; 
    }
