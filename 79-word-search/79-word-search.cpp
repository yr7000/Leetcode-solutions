class Solution {
public:
    bool dfs(int x,int y,vector<vector<char>>& board,string word,int n,int m){
        if(word.size()==0) return true;
        if(x<0 or y<0 or x>=n or y>=m or board[x][y]!=word[0]) return false;
        board[x][y] = '#';
        if(dfs(x+1,y,board,word.substr(1),n,m)) return true;
        if(dfs(x,y+1,board,word.substr(1),n,m)) return true;
        if(dfs(x,y-1,board,word.substr(1),n,m)) return true;
        if(dfs(x-1,y,board,word.substr(1),n,m)) return true;
        board[x][y] = word[0];
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        if(word.size() > n*m) return false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dfs(i,j,board,word,n,m)) return true;
            }
        }
        return false;
    }
};