class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        for(char bracket:s){
            if(bracket == '('){
                st.push('(');
            }else{
                if(st.empty() or st.top()!='('){
                    st.push(')');
                }else{
                    st.pop();
                }
            }
        }
        return st.size();    
    }
};