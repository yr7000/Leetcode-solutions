class Solution {
public:
    void sortColors(vector<int> &nums) {
        int forZero = 0,forTwo = nums.size()-1,i=0;
        while(i<=forTwo){
            if(nums[i]==0){
                swap(nums[i++],nums[forZero++]);
            }else if(nums[i]==2){
                swap(nums[i],nums[forTwo--]);
            }else{
                i++;
            }
        }
    }
};