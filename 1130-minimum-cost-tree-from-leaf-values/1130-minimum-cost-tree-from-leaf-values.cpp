#define vivi vector<vector<int>>
class Solution {
public:
    
    int dp(vector<int> &arr,int i,int j, vivi &memo ){
        if(i>=j) return 0;
        if(j-i == 1) return arr[i]*arr[j];
        if(memo[i][j]!=-1) return memo[i][j];
        
        int sizeOfRange = j-i+1;
        int maxRight[sizeOfRange];
        maxRight[sizeOfRange-1] = arr[j];
        for(int k = sizeOfRange-2;k>=0;k--){
            maxRight[k] = max(maxRight[k+1],arr[k+i]);
        }
        
        int bestResult = INT_MAX;        
        int maxLeft = INT_MIN;
        for(int k=i;k<j;k++){
            maxLeft = max(maxLeft,arr[k]);
            int mxRight = maxRight[k-i+1];
            int choise = dp(arr,i,k,memo) + dp(arr,k+1,j,memo) + maxLeft*mxRight;
            bestResult = min(bestResult,choise);
        }
        return memo[i][j] = bestResult;
    }
    
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        vivi memo(n,vector<int>(n,-1));
        return dp(arr,0,n-1,memo);
    }
};