class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        int changedNum = 0;
        int mul = 1;
        while(n>0){
            if(!(n&1)){
                changedNum += mul; 
            }
            mul *= 2;
            n>>=1;
        }
        return changedNum;
    }
};