class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int numsSize = nums.size();
        int leftProduct = 1, rightProduct = 1;
        int leftPtr = 0, rightPtr = numsSize-1;
        vector<int> result(numsSize,1);
        while(leftPtr<nums.size()){
            result[leftPtr] *= leftProduct;
            result[rightPtr] *= rightProduct;
            leftProduct *= nums[leftPtr++];
            rightProduct *= nums[rightPtr--];
        }
        return result;
    }
};