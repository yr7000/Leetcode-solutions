class Solution {
public:
    
    bool good(vector<int>& piles,int m,int h){
        int hourCount = 0;
        for(int i:piles){
            hourCount += ceil((double)i/(double)m);
        }
        return hourCount<=h;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 0, r = *max_element(piles.begin(),piles.end());
        while(r>(l+1)){
            int m = l+(r-l)/2;
            good(piles,m,h)?r = m:l=m;
        }
        return r;
    }
};