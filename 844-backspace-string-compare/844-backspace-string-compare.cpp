class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> S,T;
        for(int i=0;i<s.size();i++){
            if(s[i]!='#') S.push(s[i]);
            else if(!S.empty()) S.pop();
        }
        for(int i=0;i<t.size();i++){
            if(t[i]!='#') T.push(t[i]);
            else if(!T.empty()) T.pop();
        }
        if(S.size()!=T.size()) return false;
        while(!S.empty()){
            if(S.top()!=T.top()) return false;
            S.pop();
            T.pop();
        }
        return true;
    }
};