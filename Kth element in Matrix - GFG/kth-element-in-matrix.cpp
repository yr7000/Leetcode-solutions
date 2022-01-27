// { Driver Code Starts
// kth largest element in a 2d array sorted row-wise and column-wise
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);
// driver program to test above function
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
    
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>mat[i][j];
        int r;
        cin>>r;
        cout<<kthSmallest(mat,n,r)<<endl;
    }
     // cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
      return 0;
}
// } Driver Code Ends



int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    int l = mat[0][0], r = mat[n-1][n-1]+1;
    
    while(r>(l+1)){
        int m = l+(r-l)/2;
        
        int count = 0;
        for(int i=0;i<n;i++){
            count += lower_bound(mat[i],mat[i]+n,m)-mat[i];
        }
        if(count<k){
            l = m;
        }else{
            r = m;
        }
    }
    return l;
}
