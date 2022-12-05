//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends



int countRev (string s)
{
    int result = 0;
    stack<int> st;
    for(auto bracket : s){
        if(bracket == '{'){
            st.push('{');
        }else{
            if(st.empty()) {
                st.push('}');
                result++;
            }
            else st.pop();
        }
    }
    if(st.size()&1) return -1;
    return st.size()/2 + result;
}