// Problem: 1108. Defanging an IP Address
// URL: https://leetcode.com/problems/defanging-an-ip-address/
// Language: cpp
class Solution {
public:
    string defangIPaddr(string address) {
        string ans = "";
        for(int i=0; i<address.size(); i++){
            if(address[i] == '.') ans += "[.]";
            else ans += address[i];
        }
        return ans;
    }
};
