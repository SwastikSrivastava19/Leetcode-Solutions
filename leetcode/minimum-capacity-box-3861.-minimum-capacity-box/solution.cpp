// Problem: 3861. Minimum Capacity Box
// URL: https://leetcode.com/problems/minimum-capacity-box/
// Language: cpp
class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int n = capacity.size();
        int ans = -1;
        int minCap = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (capacity[i] >= itemSize && capacity[i] < minCap) {
                minCap = capacity[i];
                ans = i;
            }
        }

        return ans;
    }
};
