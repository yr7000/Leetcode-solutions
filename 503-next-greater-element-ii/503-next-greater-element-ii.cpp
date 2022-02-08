class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        stack<int> s;
        for(int i=2*n-1;i>=0;i--){
            while(!s.empty() and nums[i%n]>=nums[s.top()]) s.pop();
            if(s.empty()) result[i%n] = -1;
            else result[i%n] = nums[s.top()];
            s.push(i%n);
        }
        return result;
    }
};