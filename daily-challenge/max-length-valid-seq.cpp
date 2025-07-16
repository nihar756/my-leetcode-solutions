// You are given an integer array nums.
// A subsequence sub of nums with length x is called valid if it satisfies:

// (sub[0] + sub[1]) % 2 == (sub[1] + sub[2]) % 2 == ... == (sub[x - 2] + sub[x - 1]) % 2.
// Return the length of the longest valid subsequence of nums.

// A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(4,0);
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                dp[0]++;
                dp[2]=dp[3]+1;
            }
            else{
                dp[1]++;
                dp[3]=dp[2]+1;
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};