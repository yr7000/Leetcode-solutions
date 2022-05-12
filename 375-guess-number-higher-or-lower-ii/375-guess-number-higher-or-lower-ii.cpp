class Solution {
public:
    
    // whats your job ?
    // you have to guess a number
    // so lets a guess a number between the current range( initally [1,n])
    // if this my pick then he can say either go to left or go to right 
    // so we calculate the cost required recursively
    // max of those 2 values tells the worst cost that may be possible if i start picking the current picked number 
    // and we choose the min of all the worst cost associated with each pick 
    
    int memo[201][201];
    int dp(int l, int r){
        if(l>=r) return 0;
        if(memo[l][r]!=-1) return memo[l][r];
        int result = INT_MAX;
        for(int guess = l; guess <=r; guess++){
            int leftCost = dp(l,guess-1) + guess;
            int rightCost = dp(guess+1,r) + guess;
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