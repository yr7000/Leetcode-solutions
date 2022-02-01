class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = -1, r = nums.size()-1;
        while(r>(l+1)){
            int m = l+(r-l)/2;
            if(nums[m]==nums[r]) r--;
            else if(nums[m]<nums[r]) r = m;
            else l = m;
        }
        return nums[r];
    }
};