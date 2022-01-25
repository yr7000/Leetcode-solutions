class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k>1){
            sort(s.begin(),s.end());
            return s;
        }
        int n = s.size();
        string result = s;
        s += s;
        int minInd = 0;
        for(int i=1;i<n;i++){
            if(s.substr(i,n) < result) result = s.substr(i,n);
        }
        return result;
    }
};