class Solution {
public:
    int longestValidParentheses(string str) {
        stack<int> s;
        s.push(-1);
        int result = 0;
        for(int i=0;i<str.size();i++){
            char c = str[i];
            if(c=='('){
                s.push(i);
            }else{
                s.pop();
                if(s.empty()){
                    s.push(i);
                }else{
                    result = max(result,i-s.top());
                }
            }
        }
        return result;
    }
};