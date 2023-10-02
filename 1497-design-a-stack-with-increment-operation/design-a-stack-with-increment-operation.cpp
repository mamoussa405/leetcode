class CustomStack {
    vector<int> s;
    int _maxSize;
public:
    CustomStack(int maxSize) {
       _maxSize = maxSize; 
    }
    
    void push(int x) {
        if (s.size() + 1 <= _maxSize)
            s.push_back(x);
    }
    
    int pop() {
       if (s.empty()) 
        return -1;
       int top = s.back();
       s.pop_back();
       return top; 
    }
    
    void increment(int k, int val) {
        int i = -1;
        k = (k <= s.size()) ? k : s.size();
        while (k--)
            s[++i] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */