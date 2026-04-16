// Problem: 3488. Closest Equal Element Queries
// URL: https://leetcode.com/problems/closest-equal-element-queries/
// Language: cpp
// class Solution {
// public:
//     vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
//         int n = nums.size();
//         vector<int> ans;

//         for(int q : queries){
//             int target = nums[q];
//             int mini = INT_MAX;

//             for(int i=0; i<n; i++){    // [1  3  1  4  1  3  2]
//                 if(nums[i] == target && i != q){
//                     int directDist = abs(i - q);
//                     int circularDist = n - directDist;
//                     mini = min(mini , min(directDist, circularDist));
//                 }
//             }

//             if(mini == INT_MAX) ans.push_back(-1);
//             else ans.push_back(mini);
//         }
//         return ans;
//     }
// };

// from discussion
    // Hint 1: Use a HashMap to store the indices of each number in nums. The
    // key should be nums[i], and the value should be a list of indices where
    // nums[i] appears.

    // Hint 2: For each query, retrieve the stored list of indices for
    // nums[queries[i]].

    // Hint 3: Use binary search to efficiently find the next occurrence of the
    // number. This reduces the lookup time to O(log N) instead of O(N).

    // Final Complexity: O(N) + O(Q log N).

    class Solution {
    public:
        vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
            int n = nums.size();
            vector<int> ans(queries.size());

            unordered_map<int, vector<int>> freq;
            for(int i=0; i<n; i++){
                freq[nums[i]].push_back(i);
            }

            for(int i=0; i<queries.size(); i++){
                int q = queries[i];
                int val = nums[q];
                vector<int>& ind = freq[val];

                if(ind.size() == 1){
                    ans[i] = -1;
                    continue;
                }

                int pos = lower_bound(ind.begin(), ind.end(), q) - ind.begin();

                int prevIdx = ind[(pos - 1 + ind.size()) % ind.size()];
                int nextIdx = ind[(pos + 1) % ind.size()];

                int dist1 = abs(q - prevIdx);
                int dist2 = abs(q - nextIdx);

                ans[i] = min(min(dist1, n - dist1), min(dist2, n - dist2));
            }

            return ans;
        }
    };
