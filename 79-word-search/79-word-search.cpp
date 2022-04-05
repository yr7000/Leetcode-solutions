class Solution {
public:
    int dx[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
    bool dfs(int x,int y,vector<vector<char>>& board,vector<vector<bool>> &visited,string word,int n,int m){
        if(word.size()==0) return true;
        if(x<0 or y<0 or x>=n or y>=m or visited[x][y] or board[x][y]!=word[0]) return false;
        visited[x][y] = true;
        for(int i=0;i<4;i++){
            int X = x + dx[i][0];
            int Y = y + dx[i][1];
            if(dfs(X,Y,board,visited,word.substr(1),n,m)) return true;
        }
        visited[x][y] = false;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]!=word[0]) continue;
                vector<vector<bool>> visited(n,vector<bool>(m,false));
                if(dfs(i,j,board,visited,word,n,m)) return true;
            }
        }
        return false;
    }
};