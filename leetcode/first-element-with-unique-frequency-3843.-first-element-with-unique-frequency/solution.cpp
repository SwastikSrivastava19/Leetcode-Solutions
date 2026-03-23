// Problem: 3843. First Element with Unique Frequency
// URL: https://leetcode.com/problems/first-element-with-unique-frequency/
// Language: cpp
class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int , int> freq;
        unordered_map<int , int> freqCnt;

        for(auto it : nums) freq[it]++;
        for (auto a : freq) freqCnt[a.second]++;

        for(int i=0; i<nums.size(); i++){
            if(freqCnt[freq[nums[i]]] == 1) return nums[i];
        }
        return -1;
    }
};
