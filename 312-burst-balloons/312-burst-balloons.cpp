class Solution {
public:
    int memo[301][301];
    
    int dp(int i, int j, vector<int> &nums){
        if(i>j) return 0;
        if(memo[i][j]!=-1) return memo[i][j];
        int result = 0;
        for(int lastBalloon = i; lastBalloon<=j; lastBalloon++){
            int leftBalloon = (i == 0)?1:nums[i-1];
            int rightBalloon = (j == nums.size()-1)?1:nums[j+1];
            int coins = leftBalloon * rightBalloon * nums[lastBalloon] + dp(i,lastBalloon-1,nums) + dp(lastBalloon+1,j,nums);
            result = max(result,coins);         
        }
        return memo[i][j] = result;
    }
    
    int maxCoins(vector<int>& nums) {
        memset(memo,-1,sizeof(memo));
        return dp(0,nums.size()-1,nums);
    }
};