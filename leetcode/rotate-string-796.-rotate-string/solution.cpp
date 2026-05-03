// Problem: 796. Rotate String
// URL: https://leetcode.com/problems/rotate-string/
// Language: cpp
class Solution {
public:
    bool rotateString(string s, string goal) {
        // for(int i=1; i<=s.size(); i++){
        //     string str = s.substr(i) + s.substr(0 , i);

        //     if(str == goal) return true;
        // }
        // return false;
        // better approach ->>>

        if (s.size() != goal.size()) return false;


        string DoubleSize = s +s;

        return DoubleSize.find(goal) != string::npos;
    }
};
