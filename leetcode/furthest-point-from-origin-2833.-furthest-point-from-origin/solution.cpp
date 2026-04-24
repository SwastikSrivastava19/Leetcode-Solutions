// Problem: 2833. Furthest Point From Origin
// URL: https://leetcode.com/problems/furthest-point-from-origin/
// Language: cpp
class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int r = 0 , l = 0 , c = 0;
        for(int i=0; i<moves.size(); i++){
            if(moves[i] == 'L') l++;
            else if(moves[i] == 'R') r++;
            else c++;
        }
        // char change = l > r ? 'L' : 'R';
        // for(int i=0; i<moves.size(); i++){
        //     if(moves[i] == '_') moves[i] = change;
        // }

        // int ans = 0;
        // for(int i=0; i<moves.size(); i++){
        //     if(moves[i] == 'L') ans -= 1;
        //     else ans += 1;
        // }
        return abs(l - r) + c;

    }
};
