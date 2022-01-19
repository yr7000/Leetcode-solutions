class Solution {
public:
    vector<int> result;
    
    void getSpiral(vector<vector<int>>& matrix,int r,int c){
        int n = matrix.size();
        int m = matrix[0].size();
        if(r>(n-1-r)) return;
        if(c<(m-1-c)) return;
        for(int i=m-c-1;i<=c;i++){
            result.push_back(matrix[r][i]);
        }
        for(int i=r+1;i<=n-r-1;i++){
            result.push_back(matrix[i][c]);
        }
        for(int i=c-1;i>=m-c-1;i--){
            result.push_back(matrix[n-r-1][i]);
        }
        for(int i=n-r-2;i>r;i--){
            result.push_back(matrix[i][m-c-1]);
        }
        getSpiral(matrix,r+1,c-1);
    }
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        getSpiral(matrix,0,m-1);    
        while(result.size()>(n*m)) result.pop_back();
        return result;
    }
};