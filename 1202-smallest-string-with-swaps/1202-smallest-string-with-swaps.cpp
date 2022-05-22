class Solution {
public:
    
    int find(int ele, vector<int> &parent){
        return (ele==parent[ele]?ele:parent[ele] = find(parent[ele],parent));
    }
    
    void combine(int ele1, int ele2, vector<int> &parent, vector<int>& ranks){
        int parentOfEle1 = find(ele1,parent);
        int parentOfEle2 = find(ele2,parent);
        if(parentOfEle1==parentOfEle2) return;
        if(ranks[parentOfEle1] > ranks[parentOfEle2]){
            ranks[parentOfEle1] += ranks[parentOfEle2];
            parent[parentOfEle2] = parentOfEle1;
        }else{
            ranks[parentOfEle2] += ranks[parentOfEle1];
            parent[parentOfEle1] = parentOfEle2;           
        }
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        vector<int> parent(n);
        vector<int> ranks(n);
        for(int i=0;i<n;i++){
            parent[i] = i;
            ranks[i] = 1;
        }
        for(auto p: pairs){
            combine(p[0],p[1],parent,ranks);
        }
        map<int,pair<string,vector<int>>> m;
        for(int i=0;i<n;i++){
            parent[i] = find(i,parent);
            m[parent[i]].first.push_back(s[i]);
            m[parent[i]].second.push_back(i);
        }
        for(auto ele:m){
            sort(ele.second.first.begin(),ele.second.first.end());
            sort(ele.second.second.begin(),ele.second.second.end());
            int ptr = 0;
            for(int indexes: ele.second.second){
                s[indexes] = ele.second.first[ptr];
                ptr++;
            }
        }
        return s;
        
    }
};