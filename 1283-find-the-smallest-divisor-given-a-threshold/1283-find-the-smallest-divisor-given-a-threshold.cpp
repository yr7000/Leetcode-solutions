class Solution {
public:
    
    bool isPossible(vector<int> &nums,int threshold,int m){
        int sum = 0;
        for(auto num:nums){
            sum += ceil(num*1.0/m);
        }
        return sum<=threshold;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 0, r = *max_element(nums.begin(),nums.end())+1;
        while(r>(l+1)){
            int m = l + (r-l)/2;
            isPossible(nums,threshold,m)?r=m:l=m;
        }
        return r;
    }
};