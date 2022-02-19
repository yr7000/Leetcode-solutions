class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,double>> posTime;
        for(int i=0;i<n;i++){
            posTime.push_back({position[i],(target-position[i])*1.0/speed[i]});
        }
        sort(posTime.begin(),posTime.end());
        int fleetCount = 0;
        double currentMaxTime = 0;
        for(int i=n-1;i>=0;i--){
            if(posTime[i].second > currentMaxTime){
                currentMaxTime = posTime[i].second;
                fleetCount++;
            }
        }
        return fleetCount;
    }   
};