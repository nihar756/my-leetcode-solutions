// Given a 0-indexed integer array nums of size n, find the maximum difference between nums[i] and nums[j] (i.e., nums[j] - nums[i]), such that 0 <= i < j < n and nums[i] < nums[j].

// Return the maximum difference. If no such i and j exists, return -1.

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int max_diff=-1;
        int maxi=0;
        int n=nums.size();
        for(int i=n-1;i>=0;i--){
            if(maxi==nums[i])continue;
            max_diff=max(max_diff,maxi-nums[i]);
            maxi=max(maxi,nums[i]);
        }
        return max_diff;
    }
};