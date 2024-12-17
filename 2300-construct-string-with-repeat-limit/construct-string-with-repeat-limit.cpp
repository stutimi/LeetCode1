class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        priority_queue<pair<char, int>> maxHeap;
        for (int i = 0; i < 26; ++i) {
            if (freq[i] > 0) {
                maxHeap.push({char('a' + i), freq[i]});
            }
        }
        string result = "";
        while (!maxHeap.empty()) {
            auto [char1, count1] = maxHeap.top();
            maxHeap.pop();
            int useCount = min(count1, repeatLimit);
            result.append(useCount, char1);
            if (count1 > useCount) {
                if (maxHeap.empty()) break; 
                auto [char2, count2] = maxHeap.top();
                maxHeap.pop();
                result.push_back(char2);
                if (--count2 > 0) {
                    maxHeap.push({char2, count2});
                }
                maxHeap.push({char1, count1 - useCount});
            }
        }
        return result;
    }
};
