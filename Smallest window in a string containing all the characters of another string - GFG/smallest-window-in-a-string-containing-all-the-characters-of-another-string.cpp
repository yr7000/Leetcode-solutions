// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        int countP[26] = {0};
        int countS[26] = {0};
        int startIndex = 0;
        int bestLen = s.size()+1;
        string bestString = "-1";
        for(int i=0;i<p.size();i++) countP[p[i]-'a']++;
        for(int i=0;i<s.size();i++){
            countS[s[i]-'a']++;
            bool allFound = true;
            for(int j=0;j<26;j++){
                if(countP[j]>0 and countS[j]<countP[j]){
                    allFound = false;
                    break;
                }
            }
            if(allFound){
                for(int j=startIndex;j<=i;j++){
                    countS[s[j]-'a']--;
                    if(countP[s[j]-'a']>0 and countS[s[j]-'a']<countP[s[j]-'a']){
                        startIndex = j;
                        countS[s[j]-'a']++;
                        break;
                    }
                }
                if((i-startIndex+1)<bestLen){
                    bestLen = i-startIndex+1;
                    bestString = s.substr(startIndex,bestLen);
                }
            }
        }
        return bestString;
    }
};

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends