// Problem: 2751. Robot Collisions
// URL: https://leetcode.com/problems/robot-collisions/
// Language: cpp
class Solution {
public:
    //0->left
    // 1->right
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n=positions.size();
        unordered_map<int,int> pos_to_idx;
        //make array of robots 
        vector<vector<int>> robots;//{position,health,dir}
        for(int i=0;i<n;i++){
            int dir=directions[i]=='L'?0:1;
            robots.push_back({positions[i],healths[i],dir});
            pos_to_idx[positions[i]]=i;
        }
        //sort robots on the basis of positions
        sort(robots.begin(),robots.end());
        stack<vector<int>> st;
        for(auto &robot:robots){
            int health=robot[1];
            int dir=robot[2];
            //current robot direction is left
            if(dir==0){
                bool put=true;
                //check if theres any prev robot coming right 
                while(!st.empty() && st.top()[2]==1){
                    auto prevRobot=st.top(); st.pop();
                    //prev robot is having low health so remove it
                    if(robot[1]>prevRobot[1]){
                        robot[1]--;
                    //current robot is having low health dont take it
                    }else if(robot[1]<prevRobot[1]){
                        prevRobot[1]--;
                        st.push(prevRobot);
                        put=false;
                        break;
                    //both having equal health so remove both
                    }else{
                        put=false;
                        break;
                    }
                }
                //put the current robot
                if(put) st.push(robot);
            }else{//the current robot's direction is right so it won't collide with previous. put it simply
                st.push(robot);
            }
        }
        //as we have to return the healths in order so we will take index of each robot and sort them.
        vector<pair<int,int>> ans;
        while(!st.empty()){
            auto robot=st.top(); st.pop();
            int pos=robot[0];
            int health=robot[1];
            ans.push_back({pos_to_idx[pos],health});
        }
        sort(ans.begin(),ans.end());
        vector<int> result; // return healths in order
        for(auto &p:ans){
            result.push_back(p.second);
        }
        return result;
    }
};
