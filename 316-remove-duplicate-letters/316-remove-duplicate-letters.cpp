class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> cnt(26, 0);
        vector<bool> visited(26, false);
        for(char ch : s)  cnt[ch-'a']++;
        string result = "";
        for(char c : s) {
            cnt[c-'a']--;
            if(visited[c-'a'])  continue;
            while(!result.empty() and c < result.back() && cnt[result.back()-'a']) {
                visited[result.back()-'a'] = false;
                result.pop_back();
            }
            result += c;
            visited[c-'a'] = true;
        }
        return result;      
    }
};