class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int result = 0;
        for(auto item:items){
            if((ruleKey=="type" and item[0]==ruleValue) or (ruleKey=="color" and item[1]==ruleValue) or (ruleKey=="name" and item[2]==ruleValue)){
                result++;
            }
        }
        return result;
    }
};