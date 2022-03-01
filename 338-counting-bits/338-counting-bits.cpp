class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1);
        dp[0] = 0;
        for(int i=1;i<=n;i++){
            int exp = log(i)/log(2);
            int nearestPowerOfTwo = pow(2,exp);
            dp[i] = 1+dp[i-nearestPowerOfTwo];
        }
        return dp;
    }
};