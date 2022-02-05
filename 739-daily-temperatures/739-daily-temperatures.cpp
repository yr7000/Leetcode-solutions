class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> s;
        vector<int> result;
        for(int i=n-1;i>=0;i--){
            while(!s.empty() and temperatures[s.top()]<=temperatures[i]){
                s.pop();
            }
            if(s.empty()) result.push_back(0);
            else result.push_back(s.top()-i);
            s.push(i);
        }
        reverse(result.begin(),result.end());
        return result;
    }
};