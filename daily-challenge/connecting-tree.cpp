// There exist two undirected trees with n and m nodes, with distinct labels in ranges [0, n - 1] and [0, m - 1], respectively.

// You are given two 2D integer arrays edges1 and edges2 of lengths n - 1 and m - 1, respectively, where edges1[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the first tree and edges2[i] = [ui, vi] indicates that there is an edge between nodes ui and vi in the second tree. You are also given an integer k.

// Node u is target to node v if the number of edges on the path from u to v is less than or equal to k. Note that a node is always target to itself.

// Return an array of n integers answer, where answer[i] is the maximum possible number of nodes target to node i of the first tree if you have to connect one node from the first tree to another node in the second tree.

// Note that queries are independent from each other. That is, for every query you will remove the added edge before proceeding to the next query.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dfs(int node,int par,vector<vector<int>>&adj,int k){
        if(k<0)return 0;
        int cnt=1;
        for(auto child:adj[node]){
            if(child!=par){
                cnt+=dfs(child,node,adj,k-1);
            }
        }
        return cnt;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& e1, vector<vector<int>>& e2, int k) {
        int n=e1.size()+1;
        int m=e2.size()+1;
        vector<vector<int>>adj1(n),adj2(m);
        for(auto it:e1){
            int u=it[0],v=it[1];
            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }
        for(auto it:e2){
            int u=it[0],v=it[1];
            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }

        vector<int>ans(n);
        int maxi=0;
        for(int i=0;i<m;i++)maxi=max(maxi,dfs(i,-1,adj2,k-1));
        for(int i=0;i<n;i++)ans[i]=dfs(i,-1,adj1,k)+maxi;
        return ans;
    }
};