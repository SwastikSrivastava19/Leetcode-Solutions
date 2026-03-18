// Problem: 1561. Maximum Number of Coins You Can Get
// URL: https://leetcode.com/problems/maximum-number-of-coins-you-can-get/
// Language: cpp
class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin() , piles.end());
        int ans = 0;

        for(int i=piles.size()/3; i<piles.size(); i+=2){
            ans += piles[i];
        }
        return ans;
    }
};
