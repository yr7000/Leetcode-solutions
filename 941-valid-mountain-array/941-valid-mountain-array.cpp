class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size()<3) return false;
        bool pointReached = false;
        bool isSorted = true;
        for(int i=arr.size()-2;i>=0;i--){
            int val1 = arr[i], val2 = arr[i+1];
            if(val1==val2) return false;
            if(pointReached==false and val1<val2){
                if(i==arr.size()-2) return false;
                pointReached = true;
            }
            if(pointReached) isSorted = isSorted and val1<val2;
        }
        return isSorted and pointReached;
    }
};