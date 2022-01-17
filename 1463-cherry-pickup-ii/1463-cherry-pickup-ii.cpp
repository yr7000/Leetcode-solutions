class Solution {
public:
    
    int dx[3] = {-1,0,1};
    int dp[71][71][71];
    
    int getAns(vector<vector<int>> &grid,int row,int c1,int c2,int n,int m){
        if(row==n) return 0;
        if(c1<0 or c2<0 or c1>=m or c2>=m) return INT_MIN;
        if(dp[row][c1][c2]!=-1) return dp[row][c1][c2];
        
        int ans = 0;
        for(int i=0;i<3;i++){
            int col1 = c1-dx[i];
            for(int j=0;j<3;j++){
                int col2 = c2-dx[j];
                ans = max(ans,getAns(grid,row+1,col1,col2,n,m));
            }
        }
        ans += c1==c2?grid[row][c1]:grid[row][c1]+grid[row][c2];
        return dp[row][c1][c2] = ans;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n==0) return 0;
        int m = grid[0].size();
        memset(dp,-1,sizeof(dp));
        return getAns(grid,0,0,m-1,n,m);
    }
};