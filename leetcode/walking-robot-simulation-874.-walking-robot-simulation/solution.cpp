// Problem: 874. Walking Robot Simulation
// URL: https://leetcode.com/problems/walking-robot-simulation/
// Language: cpp
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        int dir = 0;
        int x = 0;
        int y = 0;
        // unordered_map<int, unordered_set<int>> st;
        set<pair<int, int>> st;

        for(auto &v : obstacles) {
            // st[v[0]].insert(v[1]);
            st.insert({v[0], v[1]});
        }

        int ans = 0;

        for(int &k : commands) {
            if(k == -1) {
                dir = (dir+1) % 4;
            } else if(k == -2) {
                dir = (dir-1+4) % 4;
            } else {
                for(int i=0; i<k; i++) {
                    // if(st.count(x+dx[dir]) && st[x+dx[dir]].count(y+dy[dir])) break;
                    if(st.count({x+dx[dir], y+dy[dir]})) break;
                    x += dx[dir];
                    y += dy[dir];

                    ans = max(ans, x*x+y*y);
                }
            }
        }

        return ans;
    }
};
