// link : https://practice.geeksforgeeks.org/problems/number-following-a-pattern3126/1#

string printMinNumberForPattern(string st){
        string s="";
        int i=0,j=0,c=1;
        while(i<=st.size()){
            if(st[i]=='I' || i==st.size()){
                while(c>=1){
                    if(c<=j) break;
                    char ch=c+'0';
                    s.push_back(ch);
                    c--;
                }
                j = i+1;
                c=i+1;
            }
            c++;
            i++;
        }
        return s;
    }