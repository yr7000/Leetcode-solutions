// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

//Function to generate binary numbers from 1 to N using a queue.
vector<string> generate(int N)
{
	queue<string> q;
	q.push("1");
	vector<string> result;
	while(N--){
	    string currentNumber = q.front();
	    q.pop();
	    result.push_back(currentNumber);
	    string nextNumber = currentNumber + "0";
	    string nextNextNumber = currentNumber + "1";
	    q.push(nextNumber);
	    q.push(nextNextNumber);
	}
	return result;
}


// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<string> ans = generate(n);
		for(auto it:ans) cout<<it<<" ";
		cout<<endl;
	}
	return 0;
}  // } Driver Code Ends