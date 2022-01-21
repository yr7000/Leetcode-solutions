class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int stationsCount = gas.size();
        int minInd = 0;
        for(int i=1;i<stationsCount;i++){
            gas[i] += gas[i-1];
            cost[i] += cost[i-1];
            if(gas[i]-cost[i]<gas[minInd]-cost[minInd]){
                minInd = i;
            }
        }
        int last = gas.back()-cost.back();
        if(last<0) return -1;
        return (minInd+1)%stationsCount;
    }
};