// You are given an integer array nums and a positive integer k.
// A subsequence sub of nums with length x is called valid if it satisfies:

// (sub[0] + sub[1]) % k == (sub[1] + sub[2]) % k == ... == (sub[x - 2] + sub[x - 1]) % k.
// Return the length of the longest valid subsequence of nums

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        vector<vector<int>>dp(k,vector<int>(k,0));
        int res=0;
        for(int num:nums){
            num%=k;
            for(int prev=0;prev<k;prev++){
                dp[prev][num]=dp[num][prev]+1;
                res=max(res,dp[prev][num]);
            }
        }
        return res;
    }
};