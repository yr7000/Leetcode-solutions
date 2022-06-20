class Solution {
public:
    
    void dfs(string source, string destination, map<string,vector<pair<string,double>>> &graph, set<string> &visited, double &subResult, double temp){
        if(visited.find(source)!=visited.end()) return;
        visited.insert(source);
        if(source == destination){
            subResult = temp;
            return;
        }
        for(auto connection:graph[source]){
            dfs(connection.first,destination,graph,visited,subResult,temp*connection.second);
        }
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string,vector<pair<string,double>>> graph;
        for(int i=0;i<equations.size();i++){
            graph[equations[i][0]].push_back({equations[i][1], values[i]});
            graph[equations[i][1]].push_back({equations[i][0], 1.0/values[i]});
        }
        vector<double> result;
        for(auto query: queries){
            string source = query[0];
            string destination = query[1];
            set<string> visited;
            double subResult = -1.0;
            if(graph.count(source)>0){
                dfs(source,destination,graph,visited,subResult,1.0);
            }
            result.push_back(subResult);
        }
        return result;
    }
};