class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if(n==k) return "0";
        vector<char> st;
        string result;
        for(int i=0;i<n;i++){
            while(k>0 and !st.empty() and num[i]<st.back()){
                k--;
                st.pop_back();
            }
            st.push_back(num[i]);
        }
        while(k--) st.pop_back();
        for(char c:st){
            if(c=='0' and result.empty()) continue;
            result += c;
        }
        return result.empty()?"0":result;
    }
};
