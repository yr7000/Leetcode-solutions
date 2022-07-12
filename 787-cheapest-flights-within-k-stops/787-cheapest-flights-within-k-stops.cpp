#define pii pair<int,int>
#define ll long long int
class Solution {
public:
    
    ll dfs(vector<vector<pii>> &graph, int s, int d, int k,vector<vector<int>> &dp){
        if(s == d){
            return (k<0?INT_MAX:0LL);
        }
        if(k<0) return INT_MAX;
        if(dp[s][k]!=-1) return dp[s][k];
        ll result = INT_MAX;
        for(auto nbrFlight:graph[s]){
            result = min(result,nbrFlight.second + dfs(graph,nbrFlight.first,d,k-1,dp));
        }
        return dp[s][k] = result;
    }
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pii>> graph(n);
        for(auto flight:flights){
            graph[flight[0]].push_back({flight[1],flight[2]});
        }
        k++;
        vector<vector<int>> dp(n,vector<int>(k+1,-1));
        int result = dfs(graph,src,dst,k,dp);
        return (result >= INT_MAX ? -1 : result);
    }
};