class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int>c(n, 0); 
        vector<int>freq(51, 0); 
        int count = 0;
        for (int i=0; i<n; i++) {
            freq[A[i]]++; 
            if (freq[A[i]]== 2) count++; 
            freq[B[i]]++; 
            if (freq[B[i]]== 2) count++; 
            c[i] =count;
        }
        return c;
    }
};
