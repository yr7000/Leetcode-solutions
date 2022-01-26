// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
        vector<int> v;
        int row=Mat.size();
        int col=Mat[0].size();
       
        for(int i=0;i<row;i++){
           for(int j=0;j<col;j++){
               v.push_back(Mat[i][j]);
           }
        }
        sort(v.begin(), v.end());
        int ptr = 0;
        
        for(int i=0;i<row;i++){
           for(int j=0;j<col;j++){
                Mat[i][j]=v[ptr++];
           }
        }
        return Mat;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> v(N, vector<int>(N));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) cin >> v[i][j];
        Solution ob;
        v = ob.sortedMatrix(N, v);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) cout << v[i][j] << " ";
            cout << "\n";
        }
    }
}  // } Driver Code Ends