// Problem: 2126. Destroying Asteroids
// URL: https://leetcode.com/problems/destroying-asteroids/
// Language: cpp
// Submission ID: dom-1780209705300
// Submitted At: 2026-05-31T06:41:45.365Z
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        // 10  :  3  5  9  19  21
        // 5  : 4  4  9  23
        sort(asteroids.begin() , asteroids.end());
        long long sum = mass;
        for(auto it : asteroids){
            if(sum < it){
                return false;
            }
            sum += it;
        }
        return true;
    }
};
