LINK : https://practice.geeksforgeeks.org/problems/implement-atoi/1/

 int atoi(string str) {
        int i=0;
        int ans=0;
        bool f=false;
        if(str[0]=='-'){
            i=1;
            f=true;
        }
        while(i<str.length()){
            int c=str[i]-'0';
            if(c>9 or c<0){
                return -1;
                break;
            }
            else ans=10*ans+c;
            i++;
        }
        if(f) return -1*ans;
        else return ans;
    }