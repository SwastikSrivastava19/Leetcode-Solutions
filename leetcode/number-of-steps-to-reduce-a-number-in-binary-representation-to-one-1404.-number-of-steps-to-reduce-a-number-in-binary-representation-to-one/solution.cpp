// Problem: 1404. Number of Steps to Reduce a Number in Binary Representation to One
// URL: https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/
// Language: cpp
class Solution {
public:
    void addOne(string &s){
        int n = s.size() - 1;
        while(n >= 0 && s[n] != '0'){
            s[n] = '0';
            n--;
        }
        if(n < 0){
            s = '1' + s;
        }
        else{
            s[n] = '1';
        }

    }
    int numSteps(string s) {
        int cnt = 0;

        while(s.size() > 1){
            int n = s.size() - 1;

            if(s[n] == '0') s.pop_back();

            else addOne(s);

            cnt++;
        }
        return cnt;
    }
};
