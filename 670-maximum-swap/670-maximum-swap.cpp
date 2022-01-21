class Solution {
public:
    int maximumSwap(int num) {
        string Num = to_string(num);
        int maxTillNowInd = Num.size()-1;
        int indexForSwap1 = -1,indexForSwap2 = -1;
        for(int i=Num.size()-2;i>=0;i--){
            if(Num[i]<Num[maxTillNowInd]) {
                indexForSwap1 = i;
                indexForSwap2 = maxTillNowInd; 
            }
            else if(Num[i]>Num[maxTillNowInd]) maxTillNowInd = i;
        }
        if(indexForSwap1==-1) return num;
        swap(Num[indexForSwap1],Num[indexForSwap2]);
        return stoi(Num);
    }
};