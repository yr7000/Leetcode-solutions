class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int cnt[61] = {0};
        for(auto i:time) cnt[i%60]++;
        int ans = 0;
        for(int i=1;i<30;i++) ans += cnt[i]*cnt[60-i];
        ans += cnt[30]*(cnt[30]-1)/2;
        ans += cnt[0]*(cnt[0]-1)/2;
        return ans;
    }
};