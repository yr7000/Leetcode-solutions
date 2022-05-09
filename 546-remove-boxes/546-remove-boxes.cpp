class Solution {
public:
    int memo[101][101][101];
    int dp(vector<int> &boxes, int l, int r, int extra){
        if(l>r) return 0;
        if(l>=r) return (extra+1)*(extra+1);
        if(memo[l][r][extra]!=-1) return memo[l][r][extra];
        int endPoint = l+1;
        while(boxes[l]==boxes[endPoint] and endPoint<=r){
            endPoint++;
        }
        int grpCnt = endPoint-l+extra;
        int ans = grpCnt*grpCnt + dp(boxes,endPoint,r,0);
        for(int i = endPoint+1;i<=r;i++){
            if(boxes[i]==boxes[l]){
                ans = max(ans,dp(boxes,endPoint,i-1,0)+dp(boxes,i,r,grpCnt));
            }
        }
        return memo[l][r][extra] = ans;
    }
    
    int removeBoxes(vector<int>& boxes) {
        memset(memo,-1,sizeof(memo));
        return dp(boxes,0,boxes.size()-1,0);
    }
};