// https://practice.geeksforgeeks.org/problems/word-search/1/#

bool solve(int i,int j,vector<vector<char>>& board, string word,int n,int m){
        if(word.size()==0) return true;
        if(i<0 or j<0 or i>=n or j>=m or board[i][j]!=word[0]) return false;
        char c=board[i][j];
        board[i][j]='*';
        string sub=word.substr(1);
        bool isfound =(solve(i+1,j,board,sub,n,m) or solve(i-1,j,board,sub,n,m)
        or solve(i,j+1,board,sub,n,m) or solve(i,j-1,board,sub,n,m));
        
        board[i][j]=c;
        return isfound;
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if (solve(i,j,board,word,n,m)) return true;
            }
        }
        return false;
    }