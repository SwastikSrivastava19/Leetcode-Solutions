// Problem: 2078. Two Furthest Houses With Different Colors
// URL: https://leetcode.com/problems/two-furthest-houses-with-different-colors/
// Language: cpp
class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        if(colors[0] != colors[n-1]) return n-1;
        int ans = INT_MIN;

        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(colors[i] != colors[j]){
                    ans = max(ans , abs(i-j));
                }
            }
        }
        return ans;

    }
};
