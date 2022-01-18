class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int me1 = -1, me2 = -1;
        int cnt1 = 0, cnt2 = 0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]==me1) {
                cnt1++;
            }
            else if(nums[i]==me2) {
                cnt2++;
            }
            else if(cnt1==0){
                me1 = nums[i];
                cnt1 = 1;
            }else if(cnt2==0){
                me2 = nums[i];
                cnt2 = 1;
            }else{
                cnt1--;
                cnt2--;
            }
        }
        
        vector<int> ans;
        int n = nums.size();
        cnt1 = 0;
        cnt2 = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==me1) cnt1++;
            else if(nums[i]==me2) cnt2++;
        }
        if(cnt1>(n/3)) ans.push_back(me1);
        if(cnt2>(n/3)) ans.push_back(me2);
        return ans;
    }
};