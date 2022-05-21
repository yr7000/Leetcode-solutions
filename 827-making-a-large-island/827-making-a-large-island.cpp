class Solution {
public:
    int n;
    int compNumber = 0;
    int directions[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
    void dfs(int i, int j, vector<vector<int>>& grid, int &count, vector<vector<int>>& compNumbers){
        if(i<0 or i>=n or j<0 or j>=n or grid[i][j]==0) return; 
        count++;
        grid[i][j] = 0;
        compNumbers[i][j] = compNumber;
        for(int k=0;k<4;k++){
            int I = i + directions[k][0];
            int J = j + directions[k][1];
            dfs(I,J,grid,count, compNumbers);
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        vector<int> compCount;
        vector<vector<int>> compNumbers(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int count = 0;
                    dfs(i,j,grid,count,compNumbers);
                    compCount.push_back(count);
                    compNumber++;
                }
            }
        }
        
        int bestAns = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(compNumbers[i][j]==-1){
                    int possibleAns = 0;
                    vector<bool> vis(compNumber,false);
                    for(int k=0;k<4;k++){
                        int I = i + directions[k][0];
                        int J = j + directions[k][1];
                        if(I<0 or I>=n or J<0 or J>=n or compNumbers[I][J]==-1) continue;
                        int compOfIJ = compNumbers[I][J];
                        if(vis[compOfIJ]==true) continue;
                        vis[compOfIJ] = true;
                        possibleAns += compCount[compOfIJ];
                    }
                    bestAns = max(bestAns,possibleAns+1);
                }
            }
        }
        return (bestAns==0 ? n*n : bestAns);
    }
};