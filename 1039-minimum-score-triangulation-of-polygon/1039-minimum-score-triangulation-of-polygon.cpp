class Solution {
public:
    int memo[51][51];
    int dp(int i, int j, vector<int> &values){
        if((j-i+1) < 3) return 0;
        if(memo[i][j]!=-1) return memo[i][j];
        int result = INT_MAX;
        for(int k=i+1;k<j;k++){
            result = min(result,values[i]*values[k]*values[j] + dp(i,k,values) + dp(k,j,values));
        }
        return memo[i][j] = result;
    }
    
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        memset(memo,-1,sizeof(memo));
        return dp(0,n-1,values);
    }
};