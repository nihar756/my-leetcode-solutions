// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

// You must do it in place.

#include<bits/stdc++.h>
using namespace std;

////brute force/////
void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>row(n,0),col(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    row[i]=1;
                    col[j]=1;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(row[i]==1 || col[j]==1){
                    matrix[i][j]=0;
                }
            }
        }
    }
////optimized solution////
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        queue<pair<int,int>>q;
        int n=matrix.size();
        int m=matrix[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0)q.push({i,j});
            }
        }
        //vector<vector<int>>vis(n,vector<int>(m,0));
        while(!q.empty()){
           auto [x,y]=q.front();
           q.pop();
           for(int j=0;j<m;j++)matrix[x][j]=0;
           for(int i=0;i<n;i++)matrix[i][y]=0;
        }

    }
};