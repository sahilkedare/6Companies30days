LINK : 

class Solution {
public:

    int orangesRotting(vector<vector<int>>& grid) {
         queue<pair<int,int>>q;
       for(int i=0;i<grid.size();i++){
           for(int j=0;j<grid[i].size();j++){
               if(grid[i][j]==2){
                   q.push(make_pair(i,j));
               }
           }
       }
       q.push(make_pair(-1,-1));
       int n=grid.size();
       int m=grid[0].size();
       int ans=0;
       while(q.size()!=0){
           pair<int,int>tmp=q.front();
           q.pop();
           int i=tmp.first;
           int j=tmp.second;
           if(tmp.first!=-1){
               if(i+1<n&&grid[i+1][j]==1){
                   grid[i+1][j]=2;
                   q.push(make_pair(i+1,j));
               }
               if(j+1<m&&grid[i][j+1]==1){
                   grid[i][j+1]=2;
                   q.push(make_pair(i,j+1));
               }
               if(j-1>=0&&grid[i][j-1]==1){
                   grid[i][j-1]=2;
                   q.push(make_pair(i,j-1));
               }
               if(i-1>=0&&grid[i-1][j]==1){
                   grid[i-1][j]=2;
                   q.push(make_pair(i-1,j));
               }
           }else{
               if(q.size()==0){
                //   q.pop();
                   break;
               }else{
                   ans++;
                   q.push(make_pair(-1,-1));
               }
           }
       }
       for(int i=0;i<grid.size();i++){
           for(int j=0;j<grid[i].size();j++){
               if(grid[i][j]==1){
                   return -1;;
               }
           }
       }
       return ans;
         
    }
};