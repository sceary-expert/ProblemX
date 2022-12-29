class RandomizedSet {
public:
    set<int>st;
    int sz;
    RandomizedSet() {
        sz = 0;
    }
    
    bool insert(int val) {
        st.insert(val);
        bool f = false;
        if(sz != st.size())
        {
            f= true;
            sz++;
        }
        //sz = st.size();
        return f;
    }
    
    bool remove(int val) {
        bool f = false;
        if(st.find(val) != st.end())
        {
            f = true;
            st.erase(val);
            sz--;
        }
        return f;
    }
    
    int getRandom() {
        int r = rand();
        r = r % sz;
        return *std::next(st.begin(), r);
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */