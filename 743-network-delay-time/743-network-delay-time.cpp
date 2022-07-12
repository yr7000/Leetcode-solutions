#define pii pair<int,int>
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pii>> graph(n+1);
        for(auto time:times){
            graph[time[0]].push_back({time[1],time[2]});
        }
        
        vector<int> distances(n+1,INT_MAX);
        vector<bool> visited(n+1,false);
        distances[k] = 0;
        priority_queue<pii,vector<pii>,greater<pii>> minHeap;
        minHeap.push({0,k});
        while(!minHeap.empty()){
            pii currentNodeDetails = minHeap.top();
            minHeap.pop();
            int currentNode = currentNodeDetails.second;
            int distanceFromSource = currentNodeDetails.first;
            if(visited[currentNode]) continue;
            visited[currentNode] = true;
            for(auto nbr: graph[currentNode]){
                if(distances[nbr.first] > distanceFromSource + nbr.second){
                    distances[nbr.first] = distanceFromSource + nbr.second;
                    minHeap.push({distances[nbr.first],nbr.first});
                }
            }
        }
        int result = *max_element(distances.begin()+1,distances.end());
        return (result==INT_MAX ? -1 : result);
    }
};