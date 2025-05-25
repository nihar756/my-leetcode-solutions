// You are given an array of strings words. Each element of words consists of two lowercase English letters.

// Create the longest possible palindrome by selecting some elements from words and concatenating them in any order. Each element can be selected at most once.

// Return the length of the longest palindrome that you can create. If it is impossible to create any palindrome, return 0.

// A palindrome is a string that reads the same forward and backward.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ans=0;
        unordered_map<string,int>mp;
        for(auto it:words){
            mp[it]++;
        }
        bool valid=true;
        for(auto &it:mp){
            string s=it.first;
            reverse(s.begin(),s.end());
            if(s[0]==s[1]){
                if(it.second==1 && valid){
                    ans+=2;
                    valid=false;
                }
                else{
                    if(it.second%2==1 && valid){
                        ans+=2;
                        valid=false;
                    }
                    ans+=(it.second/2) * 2*2;
                }
            }
            else if(mp.find(s)!=mp.end() && it.second>=1&&mp[s]>=1){
                ans+= 2*2*min(mp[s],it.second);
                string temp=it.first;
                mp[s]=0;
                mp[temp]=0;
            }
        }
        return ans;
    }
};
