// You are given an n x n integer matrix board where the cells are labeled from 1 to n2 in a Boustrophedon style starting from the bottom left of the board (i.e. board[n - 1][0]) and alternating direction each row.

// You start on square 1 of the board. In each move, starting from square curr, do the following:

// Choose a destination square next with a label in the range [curr + 1, min(curr + 6, n2)].
// This choice simulates the result of a standard 6-sided die roll: i.e., there are always at most 6 destinations, regardless of the size of the board.
// If next has a snake or ladder, you must move to the destination of that snake or ladder. Otherwise, you move to next.
// The game ends when you reach the square n2.
// A board square on row r and column c has a snake or ladder if board[r][c] != -1. The destination of that snake or ladder is board[r][c]. Squares 1 and n2 are not the starting points of any snake or ladder.

// Note that you only take a snake or ladder at most once per dice roll. If the destination to a snake or ladder is the start of another snake or ladder, you do not follow the subsequent snake or ladder.

// For example, suppose the board is [[-1,4],[-1,3]], and on the first move, your destination square is 2. You follow the ladder to square 3, but do not follow the subsequent ladder to 4.
// Return the least number of dice rolls required to reach the square n2. If it is not possible to reach the square, return -1.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]!=-1){
                   int num = ((n - 1 - i) * n) + ((n - 1 - i) % 2 == 0 ? (j + 1) : (n - j));

                   mp[num]=board[i][j];
                }
            }
        }
        int  min_move=INT_MAX;
        queue<pair<int,int>>q;
        vector<int>vis(n*n+1,0);
        q.push({1,0});
        vis[1]=1;
        while(!q.empty()){
            auto [num,dist]=q.front();
            q.pop();
            
            if(num==n*n)return dist;
            for(int i=1;i<=6;i++){
                int target=num+i;
                if(target <=n*n && !vis[target]){
                  vis[target]=1;
                  if(mp.find(target)!=mp.end()){
                    q.push({mp[target],dist+1});
                  }
                  else{
                    q.push({target,dist+1});
                  }
                }
            }
        }
        return -1;
    }
};