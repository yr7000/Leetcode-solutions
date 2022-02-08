// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    /*You are required to complete this method */
    
    vector<int> getNsl(int A[],int n){
        vector<int> result(n);
        stack<int> s;
        for(int i=0;i<n;i++){
            while(!s.empty() and A[s.top()]>=A[i]) s.pop();
            if(s.empty()) result[i] = 0;
            else result[i] = A[s.top()];
            s.push(i);
        }
        return result;
    }
    
    vector<int> getNsr(int A[],int n){
        vector<int> result(n);
        stack<int> s;
        for(int i=n-1;i>=0;i--){
            while(!s.empty() and A[s.top()]>=A[i]) s.pop();
            if(s.empty()) result[i] = 0;
            else result[i] = A[s.top()];
            s.push(i);
        }
        return result;       
    }
    int findMaxDiff(int A[], int n)
    {
      vector<int> nsl = getNsl(A,n);
      vector<int> nsr = getNsr(A,n);
      int result = INT_MIN;
      for(int i=0;i<n;i++){
          result = max(result,abs(nsl[i]-nsr[i]));
      }
      return result;
    }
};

// { Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
   	int n;
   	cin>>n;
   	int a[n];
   	for(int i=0;i<n;i++)
   	cin>>a[i];
   	Solution ob;
   	cout<<ob.findMaxDiff(a,n)<<endl;
   }
    return 0;
}


  // } Driver Code Ends