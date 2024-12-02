class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int index = 1, start = 0;
        for (int i = 0; i <= sentence.size(); ++i) {
            if (i == sentence.size() || sentence[i] == ' ') {
                if (sentence.substr(start, searchWord.size()) == searchWord) 
                    return index;
                start = i + 1; 
                ++index;       
            }
        }
        return -1; 
    }
};

