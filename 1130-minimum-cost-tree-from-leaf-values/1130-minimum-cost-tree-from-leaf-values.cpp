class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        vector<int> adj[16];
        for(int i=0;i<n;i++){
            adj[arr[i]].push_back(i);
        }
        
        int left[n], right[n];
        for(int i=0;i<n;i++){
            left[i] = i-1;
            right[i] = i+1;
        }
        
        int ans = 0;
        for(int i=1;i<=15;i++){
            for(int j=0;j<adj[i].size();j++){
                int index = adj[i][j];
                int bestPossibleNbr = 0;
                if(left[index]==-1 and right[index]!=n){
                    bestPossibleNbr = arr[right[index]];
                }else if(left[index]!=-1 and right[index]==n){
                    bestPossibleNbr = arr[left[index]];
                }else if(left[index]!=-1 and right[index]!=n){
                    bestPossibleNbr = min(arr[left[index]],arr[right[index]]);
                }
                
                if(left[index]!=-1){
                    right[left[index]] = right[index];
                }
                if(right[index]!=n){
                    left[right[index]] = left[index];
                }
                ans += bestPossibleNbr*i;
            }
        }
        return ans;
    }
};