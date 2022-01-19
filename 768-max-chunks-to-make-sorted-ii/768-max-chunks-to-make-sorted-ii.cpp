class Solution {
public:
    int maxChunksToSorted(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        vector<int> rightMin(n+1);
        rightMin[n] = INT_MAX;
        for(int i=n-1;i>=0;i--){
            rightMin[i] = min(nums[i],rightMin[i+1]);
        }
        rightMin[n] = INT_MIN;
        int leftMax = INT_MIN;
        for(int i=0;i<n;i++){
            leftMax = max(leftMax,nums[i]);
            if(leftMax<=rightMin[i+1]){
                ans++;
            }
        }
        return ans+1;
    }
};