#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int ret = 0;
        int n = words.size();
        
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (words[i].length() > words[j].length()) {
                    continue;
                }

                if (isPrefixAndSuffix(words[i], words[j])) {
                    ret++;
                }
            }
        }
        return ret;
    }

private:
    bool isPrefixAndSuffix(const string& str1, const string& str2) {
        int prefixLength = str1.length();
        int suffixLength = str2.length() - str1.length();

        return (str2.substr(0, prefixLength) == str1 &&
                str2.substr(suffixLength) == str1);
    }
};
