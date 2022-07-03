class Solution {
public:
    string simplifyPath(string path) {
        path += "/";
        vector<string> s;
        string curr = "";
        
        for(auto c:path){
            if(c == '/'){
                if(curr == ".."){
                    if(!s.empty()) s.pop_back();
                }
                else if(curr != "" and curr !=".") s.push_back(curr);
                curr = "";
            }else{
                curr += c;
            }
        }
        string result = "";
        for(auto str: s){
            result += "/";
            result += str;
        }
        if(result == "") return "/";
        return result;
    }
};