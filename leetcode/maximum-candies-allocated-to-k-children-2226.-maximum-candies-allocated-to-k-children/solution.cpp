// Problem: 2226. Maximum Candies Allocated to K Children
// URL: https://leetcode.com/problems/maximum-candies-allocated-to-k-children/
// Language: cpp
class Solution {
public:
    typedef long long ll;

    bool HoSktaHai(ll midd , vector<int>& candies , ll k){
        ll count = 0;

        for(int i=0; i<candies.size(); i++){
            count += candies[i] / midd;

            if(count >= k) return true;
        }
        return false;
    }

 
    int maximumCandies(vector<int>& candies, long long k) {
        ll low = 1;
        ll high = accumulate(candies.begin() , candies.end() , 0LL);
        ll ans = 0;

        while(low <= high){
            ll mid = low + (high - low)/2;

            if(HoSktaHai(mid , candies , k)){
                ans = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return ans;
    }
};
