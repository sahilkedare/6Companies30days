// LINK : https://practice.geeksforgeeks.org/problems/run-length-encoding/1/


string encode(string s)
{     
    string ans="";
    int n=s.size();
    int i=0;
    int c=0;
    while(i<n){
        c=0;
        char a=s[i];
        ans+=s[i];
        // cout<<s[i];
        while(s[i]==a){
            c++;
            i++;
        }
        ans+=to_string(c);
        // cout<<c;
    }
    return ans;
}     
 