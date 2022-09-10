class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
    int n = s.size();
    vector<bool> result;
    vector<int> prefixBit(n, 0); 
    for (int i = 0; i < n; i++) {
        int index = s[i] - 'a';
        prefixBit[i] = (i == 0)? (1<<index) : (1<<index) ^ prefixBit[i-1];
    }
    int querySize = queries.size();
    vector<bool> res;
    for (int i = 0;i<querySize;i++) {
        int left = queries[i][0];
        int right = queries[i][1];
        int subPossible = queries[i][2];
        int bits = prefixBit[right];
        if (left > 0) bits ^= prefixBit[left - 1]; 
        int setBits = __builtin_popcount(bits);
        int len = right - left + 1;
        int val = (len&1) ? (setBits - 1) / 2 <= subPossible : (setBits/2) <= subPossible;
        result.push_back(val);
    }
    return result;        
    }
};