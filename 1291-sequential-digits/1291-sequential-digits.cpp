class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string digits = "123456789";
        vector<int> result;
        for(int i=0;i<digits.size()-1;i++){
            int curNum = digits[i]-'0';
            for(int j=i+1;j<digits.size();j++){
                curNum = curNum*10 + digits[j]-'0';
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