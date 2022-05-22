class Solution {
public:
    int directions[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int zeroSum = 0, oneSum = 0;
        int n = grid.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    oneSum++;
                }else{
                    zeroSum++;
                }
            }
        }
        if(zeroSum==n*n or oneSum==n*n) return -1;
        int result = 1;
        while(!q.empty()){
            pair<int,int> currentNode = q.front();
            q.pop();
            result = max(result,grid[currentNode.first][currentNode.second]);
            for(int k=0;k<4;k++){
                int i = currentNode.first + directions[k][0];
                int j = currentNode.second + directions[k][1];
                if(i<0 or j<0 or i>=n or j>=n or grid[i][j]!=0) continue;
                grid[i][j] = grid[currentNode.first][currentNode.second]+1;
                q.push({i,j});
            }
        }
        
        return result-1;
    }
};