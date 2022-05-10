class Solution {
public:
    int memo[31][31][31];
    int mergeStoneHelper(int i, int j, int targetPiles, int prefixSum[], int k){
        
        if(memo[i][j][targetPiles]!=-1) return memo[i][j][targetPiles];
        
        if(targetPiles > (j-i+1)) return INT_MAX;
        if(i==j) return (targetPiles==1)?0:INT_MAX;
        
        if(targetPiles==1){
            int subCost = mergeStoneHelper(i,j,k,prefixSum,k);
            if(subCost!=INT_MAX) {
                if(i==0) return memo[i][j][targetPiles] = subCost+prefixSum[j];
                return memo[i][j][targetPiles] = subCost + prefixSum[j] - prefixSum[i-1];
            }
            return memo[i][j][targetPiles] = INT_MAX;
        }
        int minCost = INT_MAX;
        for(int bar = i; bar<=j-1; bar++){
            int leftCost = mergeStoneHelper(i,bar,targetPiles-1,prefixSum,k);
            if(leftCost==INT_MAX) continue;
            int rightCost = mergeStoneHelper(bar+1,j,1,prefixSum,k);
            if(rightCost==INT_MAX) continue;
            minCost = min(minCost,leftCost + rightCost);
        }
        
        return memo[i][j][targetPiles] = minCost;
    }
    
    int mergeStones(vector<int>& stones, int k) {
        // merge stones[i..j] form 1 pile
        // = merge stones[i...j] form k piles + sum(nums[i..j])
        // = merge stones[i...p] form k-1 piles + merge stones[p+1..j] form 1 pile 
        //   + sum(nums[i..j])
        memset(memo,-1,sizeof(memo));
        int n = stones.size();
        int prefixSum[n];
        prefixSum[0] = stones[0];
        for(int i=1;i<n;i++) prefixSum[i] = stones[i] + prefixSum[i-1];
        
        int result = mergeStoneHelper(0,n-1,1,prefixSum,k); 
        return (result==INT_MAX)?-1:result;
    }
};