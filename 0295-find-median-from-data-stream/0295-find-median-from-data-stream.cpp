class MedianFinder {
public:
    priority_queue<int>maxheap;
    priority_queue<int,vector<int>,greater<int>>minheap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxheap.empty()&&minheap.empty()){
            maxheap.push(num);
        }
        else{
            if(maxheap.top()<num){
                minheap.push(num);
            }
            else maxheap.push(num);
        }
       int  m=maxheap.size();
     int   n=minheap.size();
        if(m-n==2||m-n==-2){
            if(m>n){
                int temp=maxheap.top();
                maxheap.pop();
                minheap.push(temp);
            }
            else{
                int temp=minheap.top();
                minheap.pop();
                maxheap.push(temp);
                
            }
        }
        
        
    }
    
    double findMedian() {
      int  m=maxheap.size();
        int n=minheap.size();
        if(m-n==2||m-n==-2){
            if(m>n){
                int temp=maxheap.top();
                maxheap.pop();
                minheap.push(temp);
            }
            else{
                int temp=minheap.top();
                minheap.pop();
                maxheap.push(temp);
                
            }
        }
        if((m+n)%2==0){
            return ((double)maxheap.top()+(double)minheap.top())/2.0;
        }
        else {
            if(m>n){
                return maxheap.top();
            }
            else return minheap.top();
        }
        
    }//
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */