// You are given a directed graph of n nodes numbered from 0 to n - 1, where each node has at most one outgoing edge.

// The graph is represented with a given 0-indexed array edges of size n, indicating that there is a directed edge from node i to node edges[i]. If there is no outgoing edge from i, then edges[i] == -1.

// You are also given two integers node1 and node2.

// Return the index of the node that can be reached from both node1 and node2, such that the maximum between the distance from node1 to that node, and from node2 to that node is minimized. If there are multiple answers, return the node with the smallest index, and if no possible answer exists, return -1.

// Note that edges may contain cycles.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int>vis;
    void dfs(int node,int d,vector<vector<int>>&adj,unordered_map<int,int>&mp){
        mp[node]=d;
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,d+1,adj,mp);
            }
        }
    }
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            if(edges[i]!=-1){
                adj[i].push_back(edges[i]);
            }
        }
        vis.assign(n,0);
        unordered_map<int,int>mp1;
        dfs(node1,0,adj,mp1);
        vis.assign(n,0);
        unordered_map<int,int>mp2;
        dfs(node2,0,adj,mp2);
        int idx=INT_MAX;
        int dist=INT_MAX;
        for(auto it:mp1){
           if(mp2.count(it.first)){
            int d1=it.second;
            int d2=mp2[it.first];

            int maxD=max(d1,d2);
            if(maxD<dist){
                dist=maxD;
                idx=it.first;
            }
            else if(maxD==dist && it.first<idx){
                idx=it.first;
            }
           }
        }
        return idx==INT_MAX?-1:idx;
    }
};