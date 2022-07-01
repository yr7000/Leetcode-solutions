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
    
    bool similar(vector<string> x, vector<string> y){
        if(x[0]!=y[0]) return false;
        unordered_set<string> st;
        for(int i=1;i<x.size();i++) st.insert(x[i]);
        for(int j=1;j<y.size();j++){
            if(st.find(y[j])!=st.end()) return true;
        }
        return false;
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<int> parent(n), rank(n);
        for(int i=0;i<n;i++){
            parent[i] = i;
            rank[i] = 1;
        }
        unordered_map<string,int> emailToName;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                if(emailToName.count(accounts[i][j])>0){
                    Join(emailToName[accounts[i][j]],i,parent,rank);
                }else{
                    emailToName[accounts[i][j]] = i;
                }
            }
        }
        
        unordered_map<int,vector<int>> ump;
        for(int i=0;i<n;i++){
            ump[find(i,parent)].push_back(i);
        }
        
        vector<vector<string>> result;
        for(auto ele:ump){
            vector<string> subResult;
            subResult.push_back(accounts[ele.first][0]);
            set<string> ust;
            for(int i=0;i<ele.second.size();i++){
                for(int j=1;j<accounts[ele.second[i]].size();j++){
                    string currentString = accounts[ele.second[i]][j];
                    ust.insert(currentString);
                }
            }
            for(auto str:ust) subResult.push_back(str);
            result.push_back(subResult);
        }
        return result;
        
    }
};