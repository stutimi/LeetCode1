class FindSumPairs {
    vector<int>a,b;
    unordered_map<int,int>freq;

public:
    FindSumPairs(vector<int>& n1,vector<int>& n2) {
        a=n1;
        b=n2;
        for (int x : b)
            freq[x]++;
    }
    void add(int i,int val) {
        freq[b[i]]--;
        b[i] += val;
        freq[b[i]]++;
    }
    int count(int tot) {
        int ans=0;
        for (int x : a)
            ans += freq[tot-x];
        return ans;
    }
};

