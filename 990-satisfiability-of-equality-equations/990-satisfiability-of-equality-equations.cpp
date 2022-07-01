class Solution {
public:
    
    int find(int ele, vector<int>& parent){
        if(ele==parent[ele]) return ele;
        return parent[ele] = find(parent[ele],parent);
    }
    
    void Join(int ele1, int ele2, vector<int> &parent, vector<int>& rank){
        int s1 = find(ele1, parent);
        int s2 = find(ele2, parent);
        if(s1 == s2) return;
        if(rank[s1] < rank[s2]){
            rank[s2] += rank[s1];
            parent[s1] = s2;
        }else{
            rank[s1] += rank[s2];
            parent[s2] = s1;
        }
        return;
    }
    
    bool equationsPossible(vector<string>& equations) {
        vector<int> parent(26), rank(26);
        for(int i=0;i<26;i++){
            parent[i] = i;
            rank[i] = 1;
        }
        for(auto equation : equations){
            if(equation[1] == '='){
                Join(equation[0]-'a',equation[3]-'a',parent,rank);
            }
        }
        for(auto equation: equations){
            int group1 = find(equation[0]-'a',parent);
            int group2 = find(equation[3]-'a',parent);
            if(equation[1] == '!'){
                if(group1==group2) return false;
            }else{
                if(group1!=group2) return false;
            }
        }
        return true;
    }
};