class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        
        int k = nums.size();
        int mx = INT_MIN;
        for(int i=0;i<k;i++){
            mx = max(mx,nums[i][0]);
            pq.push({nums[i][0],i,0});
        }
        int mn = pq.top()[0];
        
        vector<int> result{mn,mx};
        
        while(true){
            vector<int> curMinData = pq.top();
            pq.pop();
            if(curMinData[2]==nums[curMinData[1]].size()-1) break;
            
            int nextNum = nums[curMinData[1]][curMinData[2]+1];
            mx = max(mx,nextNum);
            pq.push({nextNum,curMinData[1],curMinData[2]+1});
            mn = pq.top()[0];
            
            if(mx-mn < result[1]-result[0]){
                result[1] = mx;
                result[0] = mn;
            }
        }
        
        return result;
    }
};