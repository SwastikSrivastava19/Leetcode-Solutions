// Problem: 3819. Rotate Non Negative Elements
// URL: https://leetcode.com/problems/rotate-non-negative-elements/
// Language: cpp
class Solution {
public:
    void reverse(vector<int>& arr, int l, int r) {
        while (l < r) {
            swap(arr[l], arr[r]);
            l++;
            r--;
        }
    }

    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> pos;
        for (auto it : nums) {
            if (it >= 0) pos.push_back(it);
        }

        int n = pos.size();
        if(n == 0) return nums;

        k = k % n;

        reverse(pos, 0, k - 1);
        reverse(pos, k, n - 1);
        reverse(pos, 0, n - 1);

        vector<int> ans;
        int j = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0) ans.push_back(nums[i]);
            else ans.push_back(pos[j++]);
        }
        return ans;
    }
};
