// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string S) {
        int bestLen = INT_MAX;
        int startIndex = 0;
        int count[3] = {0};
        for(int i=0;i<S.size();i++){
            count[S[i]-'0']++;
            if(count[0]>0 and count[1]>0 and count[2]>0){
                for(int j=startIndex;j<=i;j++){
                    count[S[j]-'0']--;
                    if(count[0]==0 or count[1]==0 or count[2]==0 ){
                        startIndex = j;
                        count[S[j]-'0']++;
                        break;
                    }
                }
                if(i-startIndex+1 < bestLen){
                    bestLen = i-startIndex+1;
                }
            }
        }
        if(bestLen==INT_MAX) return -1;
        return bestLen;
    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}  // } Driver Code Ends