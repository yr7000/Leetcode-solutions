class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.size();
        vector<int> permutation(n+1);
        int l = 0, r = n;
        for(int i=0;i<n;i++){
            if(s[i]=='D'){
                permutation[i] = r;
                r--;
            }else{
                permutation[i] = l;
                l++;
            }
        }
        permutation[n] = l;
        return permutation;   
    }
};