class Solution {
public:
    
    bool are_pair(char a,char b){
        if(a=='{' and b=='}') return true;
        if(a=='[' and b==']') return true;
        if(a=='(' and b==')') return true;
        return false;
    }
    
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='{' or s[i]=='[' or s[i]=='('){
                st.push(s[i]);
            }else{
                if(st.empty() or are_pair(st.top(),s[i])==false){
                    return false;
                }
                st.pop();
            }
        }
        return st.size()==0;
    }
};