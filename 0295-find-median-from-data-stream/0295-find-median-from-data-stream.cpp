class MedianFinder {
public:
    
    priority_queue<int>mxh;
    priority_queue<int, vector<int>, greater<int>>mnh;
    //int sz;
    MedianFinder() {
        //sz = 0;
    }
    
    void addNum(int num) {
        if(mxh.size() == 0 && mnh.size() == 0)mxh.push(num);
        else{
            if(num > mxh.top())
            {
                mnh.push(num);
            }
            else  mxh.push(num);
        }
    }
    
    double findMedian() {
         while(mnh.size() + 1 < mxh.size())
         {
             mnh.push(mxh.top());
             mxh.pop();
         }
        while(mxh.size() < mnh.size()){
            mxh.push(mnh.top());
            mnh.pop();
        }
        
        //cout<<mxh.size()<<" "<<mnh.size()<<" " <<mxh.top()<<endl;
        if(mxh.size() == mnh.size())
        {
            auto ans = 0.0;
            ans += mxh.top();
            ans += mnh.top();
            
            return ans / 2.0;
        }
        
        return 1.0 * mxh.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */