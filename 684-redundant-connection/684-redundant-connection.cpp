class Solution {
public:
    
    int find(int ele,vector<int>&parent){
        return (ele==parent[ele]?ele:parent[ele] = find(parent[ele],parent));
    }
    
    void join(int g1, int g2,vector<int> &parent, vector<int>& rank){
        if(rank[g1]>rank[g2]){
            rank[g1] += rank[g2];
            parent[g2] = g1;
        }else{
            rank[g2] += rank[g1];
            parent[g1] = g2;
        }
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n),rank(n,1);
        for(int i=0;i<n;i++) parent[i] = i;
        for(auto edge:edges){
            int g1 = find(edge[0]-1,parent);
            int g2 = find(edge[1]-1,parent);
            if(g1==g2) return edge;
            join(g1,g2,parent,rank);
        }
        return {};
    }
};