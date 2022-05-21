class Solution {
public:
    
    void dfs(int source, vector<vector<int>>& isConnected, vector<bool> &visited,int n){
        visited[source] = true;
        for(int i = 0;i<n;i++){
            if(isConnected[source][i]==0 or visited[i]) continue;
            dfs(i,isConnected,visited,n);
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int provincesCount = 0;
        int n = isConnected.size();
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            if(visited[i]==false){
                provincesCount++;
                dfs(i,isConnected,visited,n);
            }
        }
        return provincesCount;
    }
};