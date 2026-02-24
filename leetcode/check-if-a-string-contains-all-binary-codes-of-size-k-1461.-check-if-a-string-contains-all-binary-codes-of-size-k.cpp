// Problem: 1461. Check If a String Contains All Binary Codes of Size K
// URL: https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/
// Language: cpp
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> st;
        int n = s.length();

        for (int i = 0; i <= n - k; i++) {
            string sub = s.substr(i, k);
            st.insert(sub);
        }
        return (st.size() == (1 << k));
    }
};
