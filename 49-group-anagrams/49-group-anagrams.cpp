class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<map<char,int>,vector<string>> mp;
        for(auto str:strs){
            map<char,int> mpTemp;
            for(auto ch:str){
                mpTemp[ch]++;
            }
            mp[mpTemp].push_back(str);
        }
        vector<vector<string>> result;
        for(auto ele:mp){
            result.push_back(ele.second);
        }
        return result;
    }
};