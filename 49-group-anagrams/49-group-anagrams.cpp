class Solution {
public:
    
    string getHash(string s){
        string hashValue = "";
        int cnt[26] = {0};
        
        for(int i=0;i<s.size();i++){
            cnt[s[i]-'a']++;
        }
        
        for(int i=0;i<26;i++){
            hashValue += to_string(cnt[i]) + (char)(i+'a') + " ";
        }
        return hashValue;
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> mp;
        for(auto str:strs){
            string hashValue = getHash(str);
            mp[hashValue].push_back(str);
        }
        vector<vector<string>> result;
        for(auto ele:mp){
            result.push_back(ele.second);
        }
        return result;
    }
};