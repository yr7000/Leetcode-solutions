class Solution {
public:
    vector<int> partitionLabels(string s) {
        int actualFrequency[26] = {0};
        for(auto c:s) actualFrequency[c-'a']++;
        int curFrequency[26] = {0};
        vector<int> ans;
        int cnt = 0;
        for(auto c:s){
            curFrequency[c-'a']++;
            cnt++;
            bool isPartitionPossible = true;
            for(int i=0;i<26;i++){
                if(curFrequency[i]==0) continue;
                isPartitionPossible = isPartitionPossible and curFrequency[i]==actualFrequency[i];
                if(!isPartitionPossible) break;
            }
            if(isPartitionPossible) {
                ans.push_back(cnt);
                cnt = 0;
            }
        }
        return ans;
    }
};