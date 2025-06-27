// You are given a string s of length n, and an integer k. You are tasked to find the longest subsequence repeated k times in string s.

// A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.

// A subsequence seq is repeated k times in the string s if seq * k is a subsequence of s, where seq * k represents a string constructed by concatenating seq k times.

// For example, "bba" is repeated 2 times in the string "bababcba", because the string "bbabba", constructed by concatenating "bba" 2 times, is a subsequence of the string "bababcba".
// Return the longest subsequence repeated k times in string s. If multiple such subsequences are found, return the lexicographically largest one. If there is no such subsequence, return an empty string

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubseq(string &s,string &target){
        int j=0;
        for(auto c:s){
            if(j<target.size() && target[j]==c)j++;
        }
        return j==target.size();
    }
    string longestSubsequenceRepeatedK(string s, int k) {
        string ans="";
        queue<string>q;
        q.push("");

        while(!q.empty()){
            string curr=q.front();q.pop();
            for(auto c='a';c<='z';c++){
                string str=curr+c;
                string rep="";
                for(int i=0;i<k;i++){
                    rep+=str;
                }

                if(isSubseq(s,rep)){
                    q.push(str);
                    if(ans.size()<str.size() || ans.size()==str.size()&& ans<str){
                        ans=str;
                    }
                }
            }
        }
        return ans;
    }
};