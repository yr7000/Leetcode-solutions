class Solution {
public:
    
    bool binarySearch(vector<int> v,int target){
        int l = 0, r = v.size()-1;
        while(l<=r){
            int m = l+(r-l)/2;
            if(v[m] == target){
                return true;
            }else if(v[m]>target){
                r = m-1;
            }else{
                l = m+1;
            }
        }
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0;i<matrix.size();i++){
            if(binarySearch(matrix[i],target)) return true;
        }
        return false;
    }
};