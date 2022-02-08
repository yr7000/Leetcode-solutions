class Solution {
public:
    
    vector<int> getNsl(vector<int> &A,int n){
        vector<int> result(n);
        stack<int> s;
        for(int i=0;i<n;i++){
            while(!s.empty() and A[s.top()]>=A[i]) s.pop();
            if(s.empty()) result[i] = i;
            else result[i] = i-s.top()-1;
            s.push(i);
        }
        return result;
    }
    
    vector<int> getNsr(vector<int> &A,int n){
        vector<int> result(n);
        stack<int> s;
        for(int i=n-1;i>=0;i--){
            while(!s.empty() and A[s.top()]>=A[i]) s.pop();
            if(s.empty()) result[i] = (n-1)-i;
            else result[i] = s.top()-i-1;
            s.push(i);
        }
        return result;       
    }
    
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nsl = getNsl(heights,heights.size());
        vector<int> nsr = getNsr(heights,heights.size());
        int ans = 0;
        for(int i=0;i<heights.size();i++){
            int mnl = nsl[i];
            int mnr = nsr[i]; 
            ans = max(ans,(mnr+mnl+1)*heights[i]);
        }
        return ans;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if(n==0) return 0;
        int m = matrix[0].size();
        vector<int> heights(m,0);
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == '0'){
                    heights[j] = 0;
                }else{
                    heights[j]++;
                }
            }
            int subans = largestRectangleArea(heights);
            ans = max(ans,subans);
        }
        return ans;
    }
};