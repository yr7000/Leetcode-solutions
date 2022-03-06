class Solution {
public:
    
    void dfs(vector<vector<int>>&graph,vector<int> &result,vector<int> &cnt,int s,int p){
        for(auto child:graph[s]){
            if(child==p) continue;
            dfs(graph,result,cnt,child,s);
            cnt[s] += cnt[child];
            result[s] += result[child] + cnt[child];
        }
    }
    
    void dfs2(vector<vector<int>>&graph,vector<int> &result,vector<int> &cnt,int s,int p){
        for(auto child:graph[s]){
            if(child==p) continue;
            result[child] = result[s]-cnt[child] + graph.size()-cnt[child];
            dfs2(graph,result,cnt,child,s);
        }   
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<int> result(n,0);
        vector<int> cnt(n,1);
        for(auto edge:edges){
            int x = edge[0], y = edge[1];
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        dfs(graph,result,cnt,0,-1);
        dfs2(graph,result,cnt,0,-1);
        return result;
    }
};