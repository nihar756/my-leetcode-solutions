// You are given an integer array nums of size n where n is a multiple of 3 and a positive integer k.

// Divide the array nums into n / 3 arrays of size 3 satisfying the following condition:

// The difference between any two elements in one array is less than or equal to k.
// Return a 2D array containing the arrays. If it is impossible to satisfy the conditions, return an empty array. And if there are multiple answers, return any of them

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i=0;i<n;i+=3){
            int a=nums[i],b=nums[i+1],c=nums[i+2];
            if(c-a>k)return {};
            ans.push_back({a,b,c});
        }
        return ans;
    }
};