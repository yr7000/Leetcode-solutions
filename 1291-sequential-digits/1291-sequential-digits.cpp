class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> result;
        for(int i=1;i<9;i++){
            int curNum = i;
            for(int j=i+1;j<10;j++){
                curNum = curNum*10 + j;
                if(curNum>=low and curNum<=high){
                    result.push_back(curNum);
                }else if(curNum>high){
                    break;
                }
            }
        }
        sort(result.begin(),result.end());
        return result;
    }
};