class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_set<char> set;
        int i = 0, j = 0;
        int maxLen = 0;

        while (j < n) {
            if (!set.count(s[j])) {
                set.insert(s[j]);
                maxLen = max(maxLen, j - i + 1);
                j++;
            } else {
                set.erase(s[i]);
                i++;
            }
        }

        return maxLen;
    }
};
