class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int dropCount[1001] = {0};
        int inCount[1001] = {0};
        for(auto trip:trips){
            dropCount[trip[2]] += trip[0];
            inCount[trip[1]] += trip[0];
        }
        for(int i=0;i<=1000;i++){
            capacity += dropCount[i];
            if(capacity<inCount[i]) return false;
            capacity -= inCount[i];
        }
        return true;
    }
};