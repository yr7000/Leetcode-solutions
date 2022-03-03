class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        stack<int> st;
        int result = 0;
        for(int x:arr){
            while(!st.empty() and x>st.top()){
                int Top = st.top();
                st.pop();
                if(st.empty()){
                    result += Top * x;
                }else{
                    result += Top * min(x,st.top());
                } 
            }
            st.push(x);
        }
        while(st.size()>1){
            int Top = st.top();
            st.pop();
            result += Top*st.top();
        }
        return result;
    
    }
};