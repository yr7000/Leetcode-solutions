class Solution {
public:
    
    int find(int ele,vector<int>&parent){
        return (ele==parent[ele]?ele:parent[ele] = find(parent[ele],parent));
    }
    
    void join(int ele1, int ele2, vector<int>&parent, vector<int>&rank){
        int g1 = find(ele1,parent);
        int g2 = find(ele2,parent);
        if(g1==g2) return;
        if(rank[g1] > rank[g2]){
            rank[g1] += rank[g2];
            parent[g2] = g1;
        }else{
            rank[g2] += rank[g1];
            parent[g1] = g2;
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        // not possible case.
        if(connections.size() < n-1) return -1;
        // answer is number of components - 1
        vector<int> parent(n),rank(n,1);
        for(int i=0;i<n;i++) parent[i] = i;
        for(auto cable:connections){
            join(cable[0],cable[1],parent,rank);
        }
        int componentsCount = 0;
        for(int i=0;i<n;i++){
            if(parent[i] == i) componentsCount++;
        }
        return componentsCount-1;
    }
};