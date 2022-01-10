// LINK : https://practice.geeksforgeeks.org/problems/is-sudoku-valid4820/1/#

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    // bool issafe(vector<vector<int>> mat,int r,int c,int n,int x){
    //     for(int i=0;i<n;i++){
    //         if(mat[i][c]==x) return false;
    //     }
    //     for(int i=0;i<n;i++){
    //         if(mat[r][i]==x) return false;
    //     }
        
    //     int a=r-(r%3);
    //     int b=c-(c%3);
    //     for(int i=0;i<3;i++){
    //         for(int j=0;j<3;j++){
    //             if(mat[a+i][b+j]==x) return false;
    //         }
    //     }
    //     return true;
    // }
    // bool solve(vector<vector<int>> mat,int r,int c,int n){
    //     if(r==n-1 and c==n){
    //         return true;
    //     }
    //     if(c==n){
    //         r++;
    //         c=0;
    //     }
        
    //     if(mat[r][c]>0) return solve(mat,r,c+1,n);
        
    //     for(int i=1;i<=n;i++){
    //         if(issafe(mat,r,c,n,i)){
    //             mat[r][c]=i;
                
    //             if(solve(mat,r,c+1,n)) return true;
    //         }
    //         mat[r][c]=0;
    //     }
    //     return false;
    // }
    
    int isValid(vector<vector<int>> mat){
        // return solve(mat,0,0,mat.size());
        // bool row[10][10] = {false}, col[10][10] = {false}, grid[10][10] = {false};
        
        // for(int i = 0; i < 9; i++) {
        //     for(int j = 0; j < 9; j++) {
                
        //         int num = mat[i][j];
        //         if(num == 0) continue;
        //         int grid_idx = (i/3) * 3 + (j/3);
                
        //         if(row[i][num] || col[j][num] || grid[grid_idx][num])
        //             return 0;
                
        //         row[i][num] = col[j][num] = grid[grid_idx][num] = true;
        //     }
        // }
        // return 1;
        unordered_set<string>mp;
          for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                int num = mat[i][j];
                if(num!=0){
                    int x=i/3;
                    int y=j/3;
                    string s=  to_string(num)+" in row "+to_string(i);
                    string s1= to_string(num)+" in column "+to_string(j);
                    string s2= to_string(num)+" in block "+ to_string(x) + " "+to_string(y);
                    
                    if(mp.find(s)!=mp.end() or mp.find(s1)!=mp.end() or mp.find(s2)!=mp.end()){
                        return false;
                    }
                    else {
                        mp.insert(s);
                         mp.insert(s1);
                          mp.insert(s2);
                    }
                    
                }
            }
        }
        return true;
    }

    
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for(int i = 0;i < 81;i++)
            cin>>mat[i/9][i%9];
        
        Solution ob;
        cout<<ob.isValid(mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends

