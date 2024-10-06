class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        // Split the sentences into words
        istringstream stream1(sentence1);
        istringstream stream2(sentence2);
        vector<string> words1, words2;
        string word;

        while (stream1 >> word) {
            words1.push_back(word);
        }
        while (stream2 >> word) {
            words2.push_back(word);
        }

        // Check if the sentences are identical
        if (words1 == words2) return true;

        // Find the length of both sentences
        int len1 = words1.size();
        int len2 = words2.size();

        // Check for similarity with possible prefix/suffix
        int prefixCount = 0;
        while (prefixCount < len1 && prefixCount < len2 && words1[prefixCount] == words2[prefixCount]) {
            prefixCount++;
        }

        // Calculate the suffix length that can be skipped
        int suffixCount = 0;
        while (suffixCount < (len1 - prefixCount) && suffixCount < (len2 - prefixCount) &&
               words1[len1 - 1 - suffixCount] == words2[len2 - 1 - suffixCount]) {
            suffixCount++;
        }

        // If the total length of the non-similar parts is less than or equal to the number of total skipped words
        return (prefixCount + suffixCount >= len1 || prefixCount + suffixCount >= len2);
    }
};
