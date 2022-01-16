class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1) return 1;
        vector<int> mp1(n+1,0),mp2(n+1,0);
        for(int i=0;i<trust.size();i++){
            mp1[trust[i][0]]++;
            mp2[trust[i][1]]++;
        }
        for(int i=1;i<=n;i++){
            if(mp2[i]==n-1 and mp1[i]==0) return i;
        }
        return -1;
    }
};
