// Problem: 3296. Minimum Number of Seconds to Make Mountain Height Zero
// URL: https://leetcode.com/problems/minimum-number-of-seconds-to-make-mountain-height-zero/
// Language: cpp
class Solution {
public:
typedef long long ll;
    bool isValid(long long T, int mountainHeight, vector<int>& workerTimes){
    
    ll reduced = 0;

    for(int t : workerTimes){

        ll low = 0, high = mountainHeight;

        while(low <= high){
            ll mid = (low + high) / 2;

            ll time = 1LL * t * mid * (mid + 1) / 2;

            if(time <= T) low = mid + 1;
            else high = mid - 1;
        }

        reduced += high;

        if(reduced >= mountainHeight) return true;
    }

    return false;
}
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        // kya ispe BS on answers lg skta hai ?
        // Bilkul lgegaaaaa
        ll low = 1;
        ll high = 1LL * (*min_element(workerTimes.begin(), workerTimes.end())) * mountainHeight * (mountainHeight + 1) / 2;

        ll ans = high;
        while(low <= high){
            ll mid = low + (high - low)/2;

            if(isValid(mid , mountainHeight , workerTimes)){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};
