class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        int poppedPointer = 0;
        int pushedPointer = 0;
        vector<bool> visited(n,false);
        while(poppedPointer < n and pushedPointer < n){
            if(visited[pushedPointer]){
                pushedPointer++;
                continue;
            }
            if(pushed[pushedPointer]==popped[poppedPointer]){
                visited[pushedPointer] = true;
                while(pushedPointer>=1 and visited[pushedPointer]) pushedPointer--;
                poppedPointer++;
            }else{
                pushedPointer++;
            }
        }
        return poppedPointer==n;
    }
};