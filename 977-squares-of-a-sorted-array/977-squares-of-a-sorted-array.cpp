class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int numsSize = nums.size();
        int i=0,j = numsSize-1;
        vector<int> result;
        while(i<=j){
            int sqrI = nums[i]*nums[i];
            int sqrJ = nums[j]*nums[j];
            if(sqrI>sqrJ){
                result.push_back(sqrI);
                i++;
            }else{
                result.push_back(sqrJ);
                j--;
            }
        }
        reverse(result.begin(),result.end());
        return result;
    }
};