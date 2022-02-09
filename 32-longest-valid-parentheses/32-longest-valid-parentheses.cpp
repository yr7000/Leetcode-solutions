class Solution {
public:
    int longestValidParentheses(string str) {
        int n = str.size();
        stack<int> s;
        vector<bool> valid(n);
        for(int i=0;i<n;i++){
            if(str[i]=='('){
                s.push(i);
            }else{
                if(!s.empty()){
                    valid[s.top()] = valid[i] = true;
                    s.pop();
                }
            }
        }
        int result = 0;
        int currentLen = 0;
        for(int i=0;i<n;i++){
            if(valid[i]==true){
                currentLen++;
            }else{
                currentLen = 0;
            }
            result = max(result,currentLen);
        }
        return result;
    }
};