// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    vector <int> calculateSpan(int price[], int n){
        vector<int> result(n);
        stack<int> s;
        for(int i=0;i<n;i++){
            while(!s.empty() and price[s.top()]<=price[i]) s.pop();
            if(s.empty()) result[i] = i+1;
            else result[i] = i-s.top();
            s.push(i);
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
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
  // } Driver Code Ends