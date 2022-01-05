// LINK : https://practice.geeksforgeeks.org/problems/decode-the-string2444/1

 string decodedString(string s){
        stack<char>st;
        string t="",t1="",ans="",num="";
        int i=0;
        while(i<s.size()){
            if(s[i]==']'){
                while(st.top()!='['){
                    t=st.top()+t;
                    st.pop();
                }
                st.pop();
                
                while(isdigit(st.top())){
                    num=st.top()+num;
                    st.pop();
                    if(st.empty()) break;
                }
                int n=stoi(num);
                
                for(int i=0;i<n;i++){
                    t1=t1+t;
                }
                if(st.empty()){
                    ans=t1;
                    break;
                } 
                for(int i=0;i<t1.size();i++){    
                     st.push(t1[i]);
                }
                t="";
                t1="";
                num="";
            }
            
            else{
                st.push(s[i]);
            }
            i++;
        }
        return ans;
    }