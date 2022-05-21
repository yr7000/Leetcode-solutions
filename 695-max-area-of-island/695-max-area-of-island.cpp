class Solution {
public:
    int directions[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    int N,M;
    void dfs(int i, int j, vector<vector<int>>& grid, int &currentArea){
        grid[i][j] = 0;
        currentArea++;
        for(int k = 0;k<4;k++){
            int I = i + directions[k][0];
            int J = j + directions[k][1];
            if(I>=0 and I<M and J>=0 and J<N and grid[I][J] == 1){
                dfs(I,J,grid,currentArea);
            }
        }
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        N = n;
        M = m;
        int maxArea = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int currentArea = 0;
                    dfs(i,j,grid,currentArea);
                    maxArea = max(maxArea,currentArea);
                }
            }
        }
        return maxArea;
    }
};