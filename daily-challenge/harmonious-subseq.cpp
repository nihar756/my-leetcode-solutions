// We define a harmonious array as an array where the difference between its maximum value and its minimum value is exactly 1.

// Given an integer array nums, return the length of its longest harmonious subsequence among all its possible subsequences

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        int ans=0;
        unordered_map<int,int>mp;
        for(auto it:nums)mp[it]++;
        for(auto [num,count]:mp){
            if(mp.find(num+1)!=mp.end()){
                ans=max(ans,count+mp[num+1]);
            }
        }
        return ans;
    }
};