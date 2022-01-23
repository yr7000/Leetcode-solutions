class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> result;
        queue<int> q;
        for(int i=1;i<=9;i++) q.push(i);
        
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            if(cur>high) break;
            if(cur>=low and cur<=high) result.push_back(cur);
            int num = cur%10;
            cur = cur*10 + (num+1);
            if(num < 9) q.push(cur);
        }
        return result;
    }
};