// You are given an integer array nums of length n and a 2D array queries, where queries[i] = [li, ri].

// For each queries[i]:

// Select a subset of indices within the range [li, ri] in nums.
// Decrement the values at the selected indices by 1.
// A Zero Array is an array where all elements are equal to 0.

// Return true if it is possible to transform nums into a Zero Array after processing all the queries sequentially, otherwise return false.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int>arr(n+1,0);
        for(auto it:queries){
            arr[it[0]]=arr[it[0]]-1;
            arr[it[1]+1]=arr[it[1]+1]+1;
        }

        vector<int>arr1(n+1,0);
        arr1[0]=arr[0];
        for(int i=1;i<n+1;i++){
           arr1[i]=arr1[i-1]+arr[i];
        }
        for(int i=0;i<n;i++){
            if(nums[i]+arr1[i]>0){
                return false;
            }
        }
        return true;
    }
};