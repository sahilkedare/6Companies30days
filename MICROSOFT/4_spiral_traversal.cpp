// LINK : https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1

// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > mat, int r, int c) 
    {
        vector<int> v;
        int left=0,right=c-1,top=0,down=r-1;
        int d=0;
        while(top<=down && left<=right){
            if(d==0){
                for(int i=left;i<=right;i++){
                    v.push_back(mat[top][i]);
                //   cout<<mat[top][i]<<" ";
                }
                top++;
            }
            else if(d==1){
                for(int i=top;i<=down;i++){
                    v.push_back(mat[i][right]);
                //   cout<<mat[i][right]<<" ";
                }
                right--;
            }
            else if(d==2){
                for(int i=right;i>=left;i--){
                    v.push_back(mat[down][i]);
                //   cout<<mat[down][i]<<" ";
                }
                down--;
            }
            else if(d==3){
                for(int i=down;i>=top;i--){
                    v.push_back(mat[i][left]);
                //   cout<<mat[top][down]<<" ";
                }
                left++;
            }
            d=(d+1)%4;
        }
        return v;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends