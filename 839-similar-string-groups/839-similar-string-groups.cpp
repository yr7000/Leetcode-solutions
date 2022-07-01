class Solution {
public:
    
    int find(int ele,vector<int>&parent){
        if(ele == parent[ele]) return ele;
        return parent[ele] = find(parent[ele],parent);
    }
    
    void Join(int s1, int s2, vector<int>& parent, vector<int>& rank){
        int groupOfS1 = find(s1,parent);
        int groupOfS2 = find(s2,parent);
        if(groupOfS1 == groupOfS2) return;
        if(rank[groupOfS1] > rank[groupOfS2]){
            rank[groupOfS1] += rank[groupOfS2];
            parent[groupOfS2] = groupOfS1;
        }else{
            rank[groupOfS2] += rank[groupOfS1];
            parent[groupOfS1] = groupOfS2;
        }
        return;
    }
    
    bool similar(string s1, string s2){
        int dif = 0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                dif++;
                if(dif==3) return false;
            }
        }
        return true;
    }
    
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        vector<int> parent(n);
        vector<int> rank(n);
        for(int i=0;i<n;i++){
            parent[i] = i;
            rank[i] = 1;
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(similar(strs[i],strs[j])){
                    Join(i,j,parent,rank);
                }
            }
        }
        int result = 0;
        for(int i=0;i<n;i++){
            if(i==parent[i]) result++;
        }
        return result;
    }
};