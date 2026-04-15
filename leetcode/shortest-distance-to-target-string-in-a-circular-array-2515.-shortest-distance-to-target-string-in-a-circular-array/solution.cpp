// Problem: 2515. Shortest Distance to Target String in a Circular Array
// URL: https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array/
// Language: cpp
class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int cnt = 0;
        int ans = INT_MAX;

        for(int i=0; i<n-1; i++){
            int circularInd = (startIndex + i) % n;
            if(words[circularInd] == target){
                ans = min(ans , cnt);
            }
            cnt++;
        }
        // (i - 1 + n) % n
        // back
        int cnt2 = 0;
        int ans2 = INT_MAX;
        for(int i=0; i<n; i++){
            int circularIndB = (startIndex - i + n) % n;
            if(words[circularIndB] == target){
                ans2 = min(ans2 , cnt2);
            }
            cnt2++;
        }
        return (min(ans , ans2) == INT_MAX) ? -1 : min(ans , ans2);
    }
};
