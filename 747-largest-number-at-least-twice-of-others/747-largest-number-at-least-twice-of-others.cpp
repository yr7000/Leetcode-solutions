class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if(nums.size()==1) return 0;
        int firstMaximum = INT_MIN, secondMaximum = INT_MIN;
        int indexOfFirstMaximum;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>firstMaximum){
                secondMaximum = firstMaximum;
                firstMaximum = nums[i];
                indexOfFirstMaximum = i;
            }else if(nums[i]>secondMaximum){
                secondMaximum = nums[i];
            }
        }
        return (secondMaximum*2)<=firstMaximum?indexOfFirstMaximum:-1;
    }
};