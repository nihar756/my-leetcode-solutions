// You are given an integer array nums and an integer k. You may partition nums into one or more subsequences such that each element in nums appears in exactly one of the subsequences.

// Return the minimum number of subsequences needed such that the difference between the maximum and minimum values in each subsequence is at most k.

// A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int cnt=1;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int lo=0;
        for(int i=0;i<n;i++){
            if(nums[i]-nums[lo]>k){
                cnt++;
                lo=i;
            }
        }
        return cnt;
    }
};