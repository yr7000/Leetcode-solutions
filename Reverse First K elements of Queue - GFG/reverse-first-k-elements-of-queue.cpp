// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k);
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        queue<int> ans = modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}// } Driver Code Ends


// User function Template for C++

// Function to reverse first k elements of a queue.

void modifyHelper(queue<int>&q,int k){
    if(k==0) return ;
    int firstEntered = q.front();
    q.pop();
    modifyHelper(q,k-1);
    q.push(firstEntered);
    return;
}

queue<int> modifyQueue(queue<int> q, int k) {
    modifyHelper(q,k);
    int count = 0;
    while(count<q.size()-k){
        count++;
        int top = q.front();
        q.pop();
        q.push(top);
    }
    return q;
}