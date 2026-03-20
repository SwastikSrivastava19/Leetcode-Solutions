// Problem: 435. Non-overlapping Intervals
// URL: https://leetcode.com/problems/non-overlapping-intervals/
// Language: cpp
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){
            return a[1] < b[1];
        });

        int lastInd = INT_MIN;

        // [[1,2],[2,3],[3,4],[1,3]]

        // [[1,2],[2,3],[1,3].[3,4]]
        int count = 0;

        for(int i=0; i<intervals.size(); i++){
            if(intervals[i][0] >= lastInd){
                count++;
                lastInd = intervals[i][1];
            }
        }
        return intervals.size() - count;
    }
};
