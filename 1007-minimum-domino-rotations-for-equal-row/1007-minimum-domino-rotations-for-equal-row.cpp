class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int ans = INT_MAX;
        int topCount[7] = {0}, bottomCount[7] = {0}, equalCount[7] = {0};
        for(int i=0;i<tops.size();i++){
            if(tops[i]==bottoms[i]){
                equalCount[tops[i]]++;
            }else{
                topCount[tops[i]]++;
                bottomCount[bottoms[i]]++;
            }
        }
        for(int i=1;i<=6;i++){
            int totalCount = topCount[i]+bottomCount[i]+equalCount[i];
            if(totalCount == tops.size()){
                ans = min({ans,topCount[i],bottomCount[i]});
            }
        }
        return ans<INT_MAX?ans:-1;
    }
};