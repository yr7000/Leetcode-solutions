class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>ind;
        for(int i=0;i<nums.size();i++){
            if(ind.count(target-nums[i])>0){
                return {ind[target-nums[i]],i};
            }
            ind[nums[i]] = i;
        }
        return {};
    }
};