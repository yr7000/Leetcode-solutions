class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>>res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-3;i++){
            if(i>0 and nums[i]==nums[i-1]) continue; // change 1
            for(int l=i+1;l<n-2;l++){
                if(l-1 != i and nums[l] == nums[l-1]) continue;
                int j=l+1;
                int k=n-1;
                long long newTarget = target - (long long)(nums[i] + nums[l]);
                while(j<k){
                    if((nums[j]+nums[k]) < newTarget) {
                        j++;
                    }
                    else if((nums[j]+nums[k]) > newTarget){
                        k--;
                    }
                    else if((nums[j]+nums[k])==newTarget){
                        vector<int>quad={nums[i],nums[l],nums[j],nums[k]};
                        res.push_back(quad);

                        j++;
                        while(j<k and nums[j]==nums[j-1]) j++; // change 2

                        k--;
                        while(j<k and nums[k]==nums[k+1]) k--; // change 3

                    }
                }
            }
        }
        return res;        
    }
};