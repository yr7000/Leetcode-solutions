class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int numsSize = nums.size();
        k = k%numsSize;
        reverse(nums.begin()+numsSize-k,nums.end());
        reverse(nums.begin(),nums.begin()+numsSize-k);
        reverse(nums.begin(),nums.end());
        return;
    }
};

/*
Time complexity  : O(n)
Space complexity : O(1)
*/