class Solution {
public:
    
    bool isPossible(vector<int> &nums,int m,int mid){
        int subArrayCnt = 1;
        int subArraySum = 0;
        for(auto num:nums){
            if(num>mid) return false;
            if(subArraySum+num <= mid){
                subArraySum += num;
            }else{
                subArrayCnt++;
                subArraySum = num;
            }
        }
        return subArrayCnt <= m;
    }
    
    int splitArray(vector<int>& nums, int m) {
        int sumOfNums = 0;
        for(auto num:nums) sumOfNums += num;
        
        int l = -1, r = sumOfNums;
        
        while(r>(l+1)){
            int mid = l+(r-l)/2;
            isPossible(nums,m,mid)?r=mid:l=mid;
        }
        return r;
    }
};