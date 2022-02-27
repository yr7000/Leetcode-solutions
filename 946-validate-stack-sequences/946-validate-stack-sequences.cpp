class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        int poppedPointer = 0;
        int pushedPointer = 0;
        vector<bool> poppedOut(n,false);
        while(poppedPointer < n and pushedPointer < n){
            if(poppedOut[pushedPointer]){
                pushedPointer++;
                continue;
            }
            if(pushed[pushedPointer]==popped[poppedPointer]){
                poppedOut[pushedPointer] = true;
                while(pushedPointer>=1 and poppedOut[pushedPointer]) pushedPointer--;
                poppedPointer++;
            }else{
                pushedPointer++;
            }
        }
        return poppedPointer==n;
    }
};