class Solution {
public:
    
    bool check(int board[][3]){
        for(int i = 0;i<3;i++){
            if(board[i][0] == board[i][1] and board[i][1]== board[i][2]) return true;
            if(board[0][i] == board[1][i] and board[1][i]== board[2][i]) return true;
        }
        if(board[0][0] == board[1][1] and board[1][1] == board[2][2]) return true;
        if(board[0][2] == board[1][1] and board[1][1] == board[2][0]) return true;
        return false;
    }
    
    string tictactoe(vector<vector<int>>& moves) {
        int board[3][3];
        for(int i = 0;i<moves.size();i++){
            int x = moves[i][0], y = moves[i][1];
            board[x][y] = (i&1 ? 1 : 2);
            if(check(board)) return (i&1 ? "B" : "A");
        }
        if(moves.size()!=9) return "Pending";
        return "Draw";
    }
};