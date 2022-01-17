class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string,char> mappings;
        unordered_set<char> chars;
        
        int i = 0;
        int wordCount = 0;
        s += ' ';
        
        int n = s.size();
        string currentWord = "";
        string str = "";
        while(i<n){
            if(s[i]==' '){
                if(mappings.find(str)==mappings.end()){
                    if(chars.find(pattern[wordCount]) != chars.end()) return false;
                    mappings[str] = pattern[wordCount];
                    chars.insert(pattern[wordCount]);
                }else{
                    if(pattern[wordCount]!=mappings[str]) return false;
                }
                str = "";
                wordCount++;
            }else{
                str += s[i];
            }
            i++;
        }
        for(auto c:pattern) chars.insert(c);
        return chars.size()==mappings.size();
    }
};