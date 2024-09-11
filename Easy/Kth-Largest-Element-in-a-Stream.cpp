class KthLargest {
public:
    multiset<int> S;

    KthLargest(int k, vector<int>& nums) {
        for(auto u: nums)
        {
            S.insert(u);
        }

        S.insert(INT_MIN);

        while(S.size() > k)
            S.erase(S.begin());
    }

    int add(int val) {
        S.insert(val);
        S.erase(S.begin());

        return *S.begin();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */