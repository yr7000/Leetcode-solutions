class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n = nums.size();
        int sumTillNow = 0;
        int result = 0;
        mp[0] = 1;
        for(int i=0;i<n;i++){
            sumTillNow += nums[i];
            if(mp.count(sumTillNow-k)){
                result += mp[sumTillNow-k];
            }
            mp[sumTillNow]++;
        }
        return result;
    }
};