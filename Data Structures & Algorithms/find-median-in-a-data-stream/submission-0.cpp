class MedianFinder {
private:
    priority_queue<int> left; // max-heap for the smaller half
    priority_queue<int, vector<int>, greater<int>> right; // min-heap for larger half

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        left.push(num);

        // Step 2: balance: move the largest of left to right
        right.push(left.top());
        left.pop();

        // Step 3: maintain size property (left >= right)
        if (left.size() < right.size()) {
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        if (left.size() > right.size())
            return left.top();
        else
            return (left.top() + right.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */