class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            if(i>0 and nums[i]==nums[i-1]) continue; // change 1
            int j=i+1;
            int k=n-1;
            while(j<k){
                if((nums[j]+nums[k]) < (-nums[i])) {
                    j++;
                }
                else if((nums[j]+nums[k]) > (-nums[i])){
                    k--;
                }
                else if((nums[j]+nums[k])==(-nums[i])){
                    vector<int>triplet={nums[i],nums[j],nums[k]};
                    res.push_back(triplet);
                    
                    j++;
                    while(j<k and nums[j]==nums[j-1]) j++; // change 2
                    
                    k--;
                    while(j<k and nums[k]==nums[k+1]) k--; // change 3
                    
                }
            }
        }
        return res;
          
    }
};