class Solution {
public:
    int directions[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int,int>> q;
        int totalFreshOranges = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    grid[i][j] = 0;
                    q.push({i,j});
                }else if(grid[i][j]==0){
                    grid[i][j] = -1;
                }else if(grid[i][j]==1){
                    totalFreshOranges++;
                    grid[i][j] = -2;
                }
            }
        }
        int result = 0;
        while(!q.empty()){
            pair<int,int> currentNode = q.front();
            q.pop();
            result = max(result,grid[currentNode.first][currentNode.second]);
            for(int k=0;k<4;k++){
                int i = currentNode.first + directions[k][0];
                int j = currentNode.second + directions[k][1];
                if(i<0 or j<0 or i>=m or j>=n or grid[i][j]==-1 or grid[i][j]!=-2) continue;
                totalFreshOranges--;
                grid[i][j] = grid[currentNode.first][currentNode.second]+1;
                q.push({i,j});
            }
        }
        if(totalFreshOranges!=0) return -1;
        return result;
         
    }
};