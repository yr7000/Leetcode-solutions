//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    bool dfs(int s, vector<int> graph[], vector<bool> & visited, int parent){
        visited[s] = true;
        bool result = false;
        for(auto ele:graph[s]){
            if(ele == parent) continue;
            if(visited[ele] == false){
                result = result or dfs(ele,graph,visited, s);
                if(result) return true;
            }else{
                return true;
            }
        }
        return false;
    }
  
    // Function to detect cycle in an undirected graph.
    bool isCycle(int n, vector<int> graph[]) {
        // Code here
        vector<bool> visited(n,false);
        bool result = false;
        for(int i = 0;i<n;i++){
            if(visited[i]==false){
                result = result or dfs(i, graph, visited,-1);
                if(result) return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends