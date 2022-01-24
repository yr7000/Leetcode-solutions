class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int flipNumSum = 0;
        int result = 0;
        int sumOfNaturalNum = 0;
        for(int i=0;i<flips.size();i++){
            flipNumSum += flips[i];
            sumOfNaturalNum += (i+1);
            if(flipNumSum == sumOfNaturalNum) result++;
        }
        return result;
    }
};