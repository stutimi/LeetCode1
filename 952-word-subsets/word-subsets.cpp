 class Solution {
 public:
   vector<string> wordSubsets(vector<string> &A, vector<string> &B) {
       int b_bit = 0;
       vector<int> b_cnt(26, 0);
       for (int i = 0; i < B.size(); i++) {
           vector<int> cnt(26, 0);
           for (const char ch : B[i]) {
               b_bit |= 1 << (ch - 'a');
               cnt[ch - 'a']++;
      }
           for (int k = 0; k < 26; k++)
        b_cnt[k] = max(b_cnt[k], cnt[k]);
       
    } 
    vector<string> ans;
       for (const string &a : A) {
           int bit = 0;
           vector<int> cnt(26, 0);
           for (const char ch : a) {
               bit |= 1 << (ch - 'a');
               cnt[ch - 'a']++;
      }   
      if ((bit & b_bit) != b_bit) continue;
           bool valid = true;
           for (int k = 0; k < 26; k++) {
               if (b_cnt[k] > cnt[k]) {
                   valid = false;
                   break; 
        }
           
      }
           if (valid) ans.push_back(a);
    }
       return ans;
  }
};