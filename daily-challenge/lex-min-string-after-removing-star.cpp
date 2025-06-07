// You are given a string s. It may contain any number of '*' characters. Your task is to remove all '*' characters.

// While there is a '*', do the following operation:

// Delete the leftmost '*' and the smallest non-'*' character to its left. If there are several smallest characters, you can delete any of them.
// Return the lexicographically smallest resulting string after removing all '*' characters.

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    string clearStars(string s) {
        priority_queue<char,vector<char>,greater<>>pq;
        unordered_map<char,vector<int>>mp;
        unordered_map<int,int>idx;
        for(int i=0;i<s.size();i++){
            char c=s[i];
            if(c=='*' && !pq.empty()){
              int index=mp[pq.top()].back();
              mp[pq.top()].pop_back();
              idx[index]=-1;
              pq.pop();
            }
            else if(c!='*'){
                mp[c].push_back(i);
                idx[i]=1;
                pq.push(c);
            }
        }
        
        
        string ans="";
        for(int i=0;i<s.size();i++){
            char c=s[i];
            if(c=='*')continue;
            if(idx[i]!=-1){
                ans+=c;
            }
        }
        return ans;
    }
};