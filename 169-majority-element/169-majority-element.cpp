class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int assumedMajorityElement;
        int cnt = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==assumedMajorityElement){
                cnt++;
            }else if(cnt==0){
                assumedMajorityElement = nums[i];
                cnt = 1;
            }else{
                cnt--;
            }
        }
        return assumedMajorityElement;
    }
};