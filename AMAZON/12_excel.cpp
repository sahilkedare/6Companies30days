// LINK : https://practice.geeksforgeeks.org/problems/column-name-from-a-given-column-number4244/1/

 string colName (long long int a)
    {
        string ans="";
        while(a>0){
            int x=a%26;
            if(x==0){
                ans='Z'+ans;
                a=(a/26)-1;
            }else{
                ans=char('A'+(x-1))+ans;
                a/=26;
            }
        }
        
        return ans;
    }