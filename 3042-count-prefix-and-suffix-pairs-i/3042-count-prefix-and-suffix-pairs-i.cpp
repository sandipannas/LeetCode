class Solution {
public:
    bool isPrefixAndSuffix(const string& str1, const string& str2) {
        int n111 = str1.size(), n222 = str2.size();
        if (n111 > n222)
            return false;
        return str2.substr(0, n111) == str1 && str2.substr(n222 - n111) == str1;
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size(), count = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isPrefixAndSuffix(words[i], words[j])) {
                    ++count;
                }
            }
        }
        return count;
    }
};