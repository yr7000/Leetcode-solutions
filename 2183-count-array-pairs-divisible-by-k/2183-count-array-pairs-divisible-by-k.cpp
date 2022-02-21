class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        unordered_map<long long,long long> mp;
        long long n = nums.size();
        long long result = 0;
        for(int i=0;i<n;i++){
            long long gcd1 = __gcd(nums[i],k);
            long long gcd2 = k/gcd1;
            if(gcd2==1){
                result += i;
            }else{
                for(auto ele:mp){
                    if(ele.first%gcd2 == 0){
                        result += ele.second;
                    }
                }
            }
            mp[gcd1]++;
        }
        return result;
        
    }
};