// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{   
public:

    vector<int> countLessGreaterThanMid(vector<vector<int>> &matrix, int r, int c,int mid){
        int lessCount = 0;
        int greaterCount = 0;
        int equalCount = 0;
        for(int i=0;i<r;i++){
            auto it = lower_bound(matrix[i].begin(),matrix[i].end(),mid);
            if(it==matrix[i].end()) lessCount += c;
            else lessCount += it-matrix[i].begin();
            
            auto it1 = upper_bound(matrix[i].begin(),matrix[i].end(),mid);
            if(it1!=matrix[i].end()){
                greaterCount += c-(it1-matrix[i].begin());
            }
            equalCount += (it1-it);
        }
        return {lessCount,greaterCount,equalCount};
    }
    
    int median(vector<vector<int>> &matrix, int r, int c){
        int mn = matrix[0][0], mx = matrix[0][c-1];
        for(int i=1;i<r;i++){
            mn = min(mn,matrix[i][0]);
            mx = max(mx,matrix[i][c-1]);
        }
        
        int s = mn, e = mx;
        int size = r*c;
        while(s<=e){
            int mid = s+(e-s)/2;
            vector<int> LG = countLessGreaterThanMid(matrix,r,c,mid);
            int equal = LG[2];
            int leftReq = (size/2)-LG[0];
            int rightReq = (size/2)-LG[1];
            if(leftReq>=0 and rightReq>=0 and (equal-leftReq-rightReq)==1){
                return mid;
            }
            if(LG[1] > LG[0]){
                s = mid+1;
            }else{
                e = mid-1;
            }
        }
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}  // } Driver Code Ends