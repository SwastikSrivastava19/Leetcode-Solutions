// Problem: 202. Happy Number
// URL: https://leetcode.com/problems/happy-number/
// Language: cpp
// Submission ID: dom-1779441132740
// Submitted At: 2026-05-22T09:12:12.753Z
class Solution {
private:
    int nextNumber(int n){
        int newNumber = 0;
        while(n!=0){
            int num = n%10;
            newNumber += num*num;
            n = n/10;
        }
        return newNumber;
    }
public:
    bool isHappy(int n) {
        unordered_set<int> set;
        while(n!=1 && !set.count(n)){
            set.insert(n);
            n = nextNumber(n);
        }
        return n==1;
    }
};


