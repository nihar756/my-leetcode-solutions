// You are given two strings of the same length s1 and s2 and a string baseStr.

// We say s1[i] and s2[i] are equivalent characters.

// For example, if s1 = "abc" and s2 = "cde", then we have 'a' == 'c', 'b' == 'd', and 'c' == 'e'.
// Equivalent characters follow the usual rules of any equivalence relation:

// Reflexivity: 'a' == 'a'.
// Symmetry: 'a' == 'b' implies 'b' == 'a'.
// Transitivity: 'a' == 'b' and 'b' == 'c' implies 'a' == 'c'.
// For example, given the equivalency information from s1 = "abc" and s2 = "cde", "acd" and "aab" are equivalent strings of baseStr = "eed", and "aab" is the lexicographically smallest equivalent string of baseStr.

// Return the lexicographically smallest equivalent string of baseStr by using the equivalency information from s1 and s2.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(char node,char &minChar,unordered_map<char,vector<char>>&adj,unordered_map<char,int>&vis){
        if(node<minChar)minChar=node;
        vis[node]=1;
        for(auto child:adj[node]){
            if(!vis.count(child)){
                dfs(child,minChar,adj,vis);
            }
        }
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        
        int n=s1.size();
        unordered_map<char,vector<char>>adj;
        for(int i=0;i<n;i++){
            char u=s1[i];
            char v=s2[i];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        string s="";

        for(auto it:baseStr){
            unordered_map<char,int>vis;
            char minChar='z';
            dfs(it,minChar,adj,vis);
            s+=minChar;
        }
        return s;

    }
};


///optimal////
class DSU{
    public:
    vector<int>u;
    DSU(){
        u.resize(26);
        for(int i=0;i<26;i++)u[i]=i;
    }

    int findPar(int v){
        if(u[v]==v)return v;
        return u[v]=findPar(u[v]);
    }

    void unionBy(int l,int r){
        l=findPar(l);
        r=findPar(r);

        if(l==r)return;
        if(l<r)u[r]=l;
        else u[l]=r;
    }
};

class Solution {
public:
    string smallestEquivalentString1(string s1, string s2, string baseStr) {
        DSU dsu;
        for(int i=0;i<s1.size();i++){
            dsu.unionBy(s1[i]-'a',s2[i]-'a');
        }
        string ans;
        for(char c:baseStr){
            ans+=dsu.findPar(c-'a')+'a';
        }
        return ans;
    }
};