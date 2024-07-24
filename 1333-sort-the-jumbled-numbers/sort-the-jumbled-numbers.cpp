class Solution {
public:
int getMappedValue(int num, const vector<int>& mapping) {
    string numStr = to_string(num);
        string mappedStr;
        for (char digit : numStr) {
            mappedStr +=to_string(mapping[digit - '0']);
        }
        return stoi(mappedStr);
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> mappedNums;
        for (int num : nums) {
            mappedNums.push_back({getMappedValue(num, mapping), num});
        }
        stable_sort(mappedNums.begin(), mappedNums.end(), [](const auto& a, const auto& b) {
            return a.first < b.first;
        });
        vector<int> sortedNums;
        for (const auto& p : mappedNums) {
            sortedNums.push_back(p.second);
        }

        return sortedNums;

    }
};