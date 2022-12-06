//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    vector<string> result;
    map<char, pair<int,int>> directions;
    
    bool isValid(int x, int y, int n, vector<vector<int>> &m){
        return (x>=0 and x<n and y>=0 and y<n and m[x][y]!=0);
    }
    
    void getAllPaths(vector<vector<int>> &m, int n, string & path, int x, int y){
        if(x == n-1 and y == n-1){
            if(m[x][y]==0) return;
            result.push_back(path);
            return ;
        }
        for(auto direction : directions){
            int X = x+direction.second.first, Y = y+direction.second.second;
            if(isValid(X,Y,n,m) == false) continue;
            m[x][y] = 0;
            path.push_back(direction.first);
            getAllPaths(m,n,path,X,Y);
            path.pop_back();
            m[x][y] = 1;
        }
        return;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        if(m[0][0] == 0) return result;
        string currentPath = "";
        directions['L'] = {0,-1};
        directions['R'] = {0,1};
        directions['U'] = {-1,0};
        directions['D'] = {1,0};
        getAllPaths(m, n, currentPath,0,0);
        return result;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends