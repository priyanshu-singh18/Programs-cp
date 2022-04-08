class KthLargest {
public:
    
    priority_queue<int> pq;
    int y;
    KthLargest(int k, vector<int>& nums) {
        for(auto x : nums)
            {
                pq.push(-x);
                if(pq.size()>k){
                    pq.pop();
                }
            }
        y = k;
    }
    
    int add(int val) {
        pq.push(-val);
        if(pq.size()>y){
            pq.pop();
        }
        return -1*pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */