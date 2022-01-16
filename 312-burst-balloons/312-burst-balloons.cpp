class Solution {
public:
    int dp[505][505];
    int fun(vector<int> &nums,int l,int r){
        if(l>r) return 0;
        if(dp[l][r]!=-1) return dp[l][r];
        int ans = INT_MIN;
        int leftValue = l-1>=0?nums[l-1]:1;
        int rightValue = r+1<=nums.size()-1?nums[r+1]:1;
        for(int i=l;i<=r;i++){
            ans = max(ans,leftValue*nums[i]*rightValue + fun(nums,l,i-1) + fun(nums,i+1,r));
        }
        return dp[l][r] = ans;
    }
    
    int maxCoins(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return fun(nums,0,nums.size()-1);
    }
};