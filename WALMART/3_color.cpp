// https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color

bool winnerOfGame(string c) {
        int n=c.size();
        int a=0,b=0;
        for(int i=1;i<n-1;i++){
            if(c[i-1]==c[i] and c[i]==c[i+1]) {
                if(c[i]=='A') a++;
                else b++;
            }
        }
        return a>b;
    }