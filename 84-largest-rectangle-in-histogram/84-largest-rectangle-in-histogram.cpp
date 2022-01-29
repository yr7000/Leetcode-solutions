class Solution {
public:
    
    vector<int> Nsl(vector<int> &h){
        stack<int> s;
        vector<int> ans;
        s.push(0);
        for(int i=1;i<h.size()-1;i++){
            while(h[s.top()]>=h[i]){
                s.pop();
            }
            ans.push_back(s.top());
            s.push(i);
        }
        return ans;
    }
    
    vector<int> Nsr(vector<int> &h){
        stack<int> s;
        vector<int> ans;
        s.push(h.size()-1);
        for(int i=h.size()-2;i>=1;i--){
            while(h[s.top()]>=h[i]){
                s.pop();
            }
            ans.push_back(s.top());
            s.push(i);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        vector<int> h;
        h.push_back(-1);
        for(auto i:heights) h.push_back(i);
        h.push_back(-1);
        vector<int> nsl = Nsl(h);
        vector<int> nsr = Nsr(h);
        int ans = 0;
        for(int i=0;i<heights.size();i++){
            int mnl = nsl[i];
            int mnr = nsr[i]; 
            ans = max(ans,(mnr-mnl-1)*heights[i]);
        }
        return ans;
    }
};