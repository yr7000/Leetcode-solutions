class Solution {
public:
    bool winnerSquareGame(int n) {
        bool dp[n+1];
        dp[0] = false;
        dp[1] = true;
        for(int i=2;i<=n;i++){
            dp[i] = false;
            for(int j=1;j*j<=i;j++){
                if(dp[i-j*j]==false){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};