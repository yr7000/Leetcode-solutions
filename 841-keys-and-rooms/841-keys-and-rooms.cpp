class Solution {
public:
    void dfs(vector<vector<int>>& rooms, int source, int& count, vector<bool>& visited){
        visited[source] = true;
        count++;
        for(int roomKeys: rooms[source]){
            if(visited[roomKeys]==false){
                dfs(rooms,roomKeys,count,visited);
            }
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int count = 0;
        int n = rooms.size();
        vector<bool> visited(n,false);
        dfs(rooms,0,count,visited);
        return count==n;
    }
};