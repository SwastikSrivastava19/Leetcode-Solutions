// Problem: 3761. Minimum Absolute Distance Between Mirror Pairs
// URL: https://leetcode.com/problems/minimum-absolute-distance-between-mirror-pairs/
// Language: cpp
class Solution {
public:
    int reverseN(int a){
        int rev = 0;
        while(a > 0){
            rev = rev * 10 + (a % 10);
            a /= 10;
        }
        return rev;
    }
    
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int , vector<int>>map;

        for(int i=0; i<n; i++){
            map[nums[i]].push_back(i);  //storing indxes
        }

        int ans = INT_MAX;
        for(int i=0; i<n; i++){
            int revN = reverseN(nums[i]);

            if(map.count(revN)){
                const vector<int>& v = map[revN];
                auto it = upper_bound(v.begin() , v.end(), i);

                if(it != v.end()) ans = min(ans , *it - i);
            }
            map[nums[i]].push_back(i);
        }
        return (ans == INT_MAX ? -1 : ans);
    }
};
