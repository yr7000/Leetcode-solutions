class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zeroCount = 0, product = 1, ind;
        for(int i=0;i<nums.size();i++) {
            if(nums[i]==0){
                ind = i;
                zeroCount++;
            }else{
                product *= nums[i];
            }
        }
        vector<int> result(nums.size(),0);
        if(zeroCount>1){
            return result;
        }else if(zeroCount==1){
            result[ind] = product;
            return result;
        }else{
            for(int i=0;i<nums.size();i++) result[i] = product/nums[i];
            return result;
        }
        
    }
};