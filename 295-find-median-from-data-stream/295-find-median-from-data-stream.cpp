class MedianFinder {
public:
    
    priority_queue<int> maxHeap;
    priority_queue<int,vector<int>,greater<int>> minHeap;
    int size;
    
    MedianFinder() {
        size = 0;
    }
    
    void addNum(int num) {
        size++;
        if(maxHeap.size() <(size/2)){
            int top = minHeap.empty()?-1:minHeap.top();
            if(top==-1 or top>=num){
                maxHeap.push(num);
            }else{
                maxHeap.push(top);
                minHeap.pop();
                minHeap.push(num);
            }
            
        }else{
            int top = maxHeap.empty()?-1:maxHeap.top();
            
            if(top==-1 or num>=top) minHeap.push(num);
            else{
                minHeap.push(top);
                maxHeap.pop();
                maxHeap.push(num);
            }
        }
    }
    
    double findMedian() {
        if(size&1){
            if(maxHeap.size() > minHeap.size()) return maxHeap.top();
            return minHeap.top();
        }
        return (double)(maxHeap.top() + minHeap.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */