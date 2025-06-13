// You are given a 0-indexed integer array nums and an integer p. Find p pairs of indices of nums such that the maximum difference amongst all the pairs is minimized. Also, ensure no index appears more than once amongst the p pairs.

// Note that for a pair of elements at the index i and j, the difference of this pair is |nums[i] - nums[j]|, where |x| represents the absolute value of x.

// Return the minimum maximum difference among all p pairs. We define the maximum of an empty set to be zero.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int count(vector<int>&nums,int target){
        int n=nums.size();
        int cnt=0;
        int idx=0;
        while(idx<n-1){
            if(nums[idx+1]-nums[idx]<=target){
                cnt++;
                idx++;
            }
            idx++;
        }
        return cnt;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int lo=0,hi=nums[n-1]-nums[0];

        while(lo<hi){
            int mid=lo+(hi-lo)/2;
            if(count(nums,mid)>=p){
                hi=mid;
            }
            else{
                lo=mid+1;
            }
        }
        return lo;
    }
};