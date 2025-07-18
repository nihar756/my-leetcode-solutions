// You have n boxes labeled from 0 to n - 1. You are given four arrays: status, candies, keys, and containedBoxes where:

// status[i] is 1 if the ith box is open and 0 if the ith box is closed,
// candies[i] is the number of candies in the ith box,
// keys[i] is a list of the labels of the boxes you can open after opening the ith box.
// containedBoxes[i] is a list of the boxes you found inside the ith box.
// You are given an integer array initialBoxes that contains the labels of the boxes you initially have. You can take all 
// the candies in any open box and you can use the keys in it to open new boxes and you also can use the boxes you find in it.

// Return the maximum number of candies you can get following the rules above.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int candy=0, n=candies.size();
        queue<int>q;
        vector<int>vis(n,0);
        for(int x:initialBoxes)q.push(x);
        while(!q.empty()){
            int currBox=q.front();
            q.pop();

            if(status[currBox]==1 && !vis[currBox]){
                //vis[currBox]=1;
                candy+=candies[currBox];
                candies[currBox]=-1;
            }

            for(int key:keys[currBox]){
                status[key]=1;
                if(vis[key] && candies[key]!=-1){
                    vis[key]=false;
                    q.push(key);
                }
            }

            for(int box:containedBoxes[currBox]){
                if(candies[box]!=-1 && !vis[box])q.push(box);
            }
            vis[currBox]=true;
        }
        return candy;
    }
};