class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int dropCount[1001] = {0};
        for(auto trip:trips){
            dropCount[trip[2]] -= trip[0];
            dropCount[trip[1]] += trip[0];
        }
        for(int i=0;i<=1000 and capacity>=0;i++) capacity -= dropCount[i];
        return capacity>=0;
    }
};