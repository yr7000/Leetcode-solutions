class Solution {
public:
    
    int gcd(int a, int b){
        if(b==0) return a;
        return gcd(b,a%b);
    }
    
    int find(int node, vector<int> &parent){
        if(node==parent[node]) return node;
        return parent[node] = find(parent[node],parent);
    }
    
    void Join(int node1, int node2, vector<int> &parent, vector<int> &rank){
        int node1Group = find(node1,parent);
        int node2Group = find(node2,parent);
        if(node1Group == node2Group) return;
        if(rank[node1Group] < rank[node2Group]){
            rank[node2Group] += rank[node1Group];
            parent[node1Group] = node2Group;
        }else{
            rank[node1Group] += rank[node2Group];
            parent[node2Group] = node1Group;
        }
        return;
    }
    
    int largestComponentSize(vector<int>& nums) {
        int n = *max_element(nums.begin(),nums.end());
        vector<int> parent(n+1), rank(n+1);
        for(int i=0;i<n;i++){
            parent[i] = i;
            rank[i] = 1;
        }
        for(auto num: nums){
            for(int i=2; i*i<=num;i++){
                if(num%i == 0){
                    Join(num,i,parent,rank);
                    Join(num,num/i,parent,rank);
                }
            }
        }
        unordered_map<int, int> mp;
        int ans = 1;
        for (auto num : nums) {
            ans = max(ans, ++mp[find(num,parent)]);
        }
        return ans;
    }
};