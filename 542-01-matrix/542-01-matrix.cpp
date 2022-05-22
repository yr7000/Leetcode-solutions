class Solution {
public:
    int directions[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                }else{
                    grid[i][j] = -1;
                }
            }
        }
        while(!q.empty()){
            pair<int,int> currentNode = q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int i = currentNode.first + directions[k][0];
                int j = currentNode.second + directions[k][1];
                if(i<0 or j<0 or i>=m or j>=n or grid[i][j]!=-1) continue;
                grid[i][j] = grid[currentNode.first][currentNode.second]+1;
                q.push({i,j});
            }
        }
        return grid;
    }
};