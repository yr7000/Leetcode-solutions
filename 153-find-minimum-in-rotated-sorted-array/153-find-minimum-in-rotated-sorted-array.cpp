class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = nums.size()-1;
        while(l<=r){
            int m = l+(r-l)/2;
            if(nums[m] < (m+1<n ? nums[m+1] : INT_MAX) and nums[m] < (m>=1?nums[m-1]:INT_MAX)){
                return nums[m];
            }
            if(nums[m]<nums[r]){
                r = m-1;
            }else{
                l = m+1;
            }
        }
        return -1;
    }
};