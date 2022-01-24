class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int prevSeatedLocation = -1;
        int res = INT_MIN;
        for(int i=0;i<n;i++){
            if(seats[i]==0) continue;
            res = prevSeatedLocation==-1?i:max(res,(i-prevSeatedLocation)/2);
            prevSeatedLocation = i;
        }
        return max(res,n-1-prevSeatedLocation);
    }
};