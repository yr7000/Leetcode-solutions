class Solution {
public:
    int consecutiveNumbersSum(int m) {
        m = 2*m;
        int ans = 0;
        for(int i=1;i*i<=m;i++){
            if(m%i != 0) continue;
            if(i != m/i) {
                if(abs(i-m/i)&1) ans++;
            }
        }
        return ans;
    }
};