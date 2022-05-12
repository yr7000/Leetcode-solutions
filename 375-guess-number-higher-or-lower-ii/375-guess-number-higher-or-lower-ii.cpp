class Solution {
public:
    int memo[201][201];
    int dp(int l, int r){
        if(l>=r) return 0;
        if(memo[l][r]!=-1) return memo[l][r];
        int result = INT_MAX;
        for(int pick = l; pick <=r; pick++){
            int leftCost = dp(l,pick-1) + pick;
            int rightCost = dp(pick+1,r) + pick;
            int worstPossibleCost = max(leftCost,rightCost);
            result = min(worstPossibleCost,result);
        }
        return memo[l][r] = result;
    }
    
    int getMoneyAmount(int n) {
        memset(memo,-1,sizeof(memo));
        return dp(1,n);
    }
};