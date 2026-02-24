// Problem: 350. Intersection of Two Arrays II
// URL: https://leetcode.com/problems/intersection-of-two-arrays-ii/
// Language: cpp
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> store1(1001, 0);
        vector<int> store2(1001, 0);
        int n1 = nums1.size();
        int n2 = nums2.size();
        for (int i = 0; i < n1; i++)
            store1[nums1[i]]++;

        for (int i = 0; i < n2; i++)
            store2[nums2[i]]++;

        vector<int> ans;
        for (int i = 0; i < 1001; i++) {
            int temp = min(store1[i], store2[i]);
            while (temp--) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
