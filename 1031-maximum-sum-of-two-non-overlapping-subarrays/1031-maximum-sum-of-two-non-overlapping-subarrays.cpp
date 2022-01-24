class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int result = 0;
        int n = nums.size();
        for(int i=1;i<n;i++){
            nums[i] += nums[i-1];
        }
        for(int i=firstLen-1;i<nums.size();i++){
            int sum1 = nums[i]-(i==firstLen-1?0:nums[i-firstLen]);
            int maxSum2 = 0;
            if((i-firstLen+1) >=secondLen){
                for(int j=secondLen-1;j<=(i-firstLen);j++){
                    maxSum2 = max(maxSum2,nums[j]-(j==secondLen-1?0:nums[j-secondLen]));
                }   
            }
            if((n-i-1)>=secondLen){
                for(int j=i+secondLen;j<n;j++){
                    maxSum2 = max(maxSum2,nums[j]-nums[j-secondLen]);
                }
            }
            result = max(result,sum1+maxSum2);
        }
        return result;
    }
};