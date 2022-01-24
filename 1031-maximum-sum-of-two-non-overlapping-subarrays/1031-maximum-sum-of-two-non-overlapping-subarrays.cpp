class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int result = 0;
        int n = nums.size();
        for(int i=1;i<n;i++){
            nums[i] += nums[i-1];
        }
        int fmaxTillNow = 0,smaxTillNow = 0;
        for(int i=0;i<n;i++){
 
            int currentFirstLenSum = ((i+firstLen-1)<n ? nums[i+firstLen-1]:0)-(i==0?0:nums[i-1]);
            result = max(result,currentFirstLenSum+smaxTillNow);

            int currentSecondLenSum = ((i+secondLen-1)<n ? nums[i+secondLen-1]:0)-(i==0?0:nums[i-1]);
            result = max(result,currentSecondLenSum+fmaxTillNow);
            
            if(i>=firstLen-1){
                if(i==firstLen-1){
                    fmaxTillNow = max(fmaxTillNow,nums[i]);
                }else{
                    fmaxTillNow = max(fmaxTillNow,nums[i]-nums[i-firstLen]);
                }
            }
            
            if(i>=secondLen-1){
                if(i==secondLen-1){
                    smaxTillNow = max(smaxTillNow,nums[i]);
                }else{
                    smaxTillNow = max(smaxTillNow,nums[i]-nums[i-secondLen]);
                }
            }
            
        }
        return result;
    }
};