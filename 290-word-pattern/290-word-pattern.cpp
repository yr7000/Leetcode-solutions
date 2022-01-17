class Solution {
public:
    bool wordPattern(string pattern, string s) {
        s+= " ";
        int n = s.size();
        vector<string> mappings(26,"");
        unordered_map<char,int> mpLet;
        unordered_map<string,int>mpWord;
        for(auto c:pattern) mpLet[c]++;
        int i=0;
        int wordCnt = 0;
        string str = "";
        while(i<n){
            if(s[i]==' '){
                if(wordCnt>=pattern.size()) return false;
                mpWord[str]++;
                string mapped = mappings[pattern[wordCnt]-'a'];
                if(mapped.size()==0) mappings[pattern[wordCnt]-'a'] = str;
                else if(str!=mapped) return false;
                wordCnt++;
                str = "";
            }else{
                str += s[i];
            }
            i++;
        }
        return mpLet.size()==mpWord.size();
    }
};