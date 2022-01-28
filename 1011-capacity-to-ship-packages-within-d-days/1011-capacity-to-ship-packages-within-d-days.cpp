class Solution {
public:
    
    bool isPossibleWithMidCapacity(vector<int>& weights, int days, int mid){
        int daysReq = 1;
        int dayWeight = 0;
        for(int i=0;i<weights.size();i++){
            if(weights[i] > mid) return false;
            if(dayWeight + weights[i] <= mid){
                dayWeight += weights[i];
            }else{
                daysReq++;
                dayWeight = weights[i];
            }
        }
        return daysReq<=days;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int sumOfWeights = 0;
        for(auto wt:weights) sumOfWeights += wt;
        
        int l = 0, r = sumOfWeights;
        while(r>(l+1)){
            int mid = l+(r-l)/2;
            isPossibleWithMidCapacity(weights,days,mid)?r=mid:l=mid;
        }
        return r;
    }
};