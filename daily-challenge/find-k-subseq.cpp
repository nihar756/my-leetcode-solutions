// You are given an integer array nums and an integer k. You want to find a subsequence of nums of length k that has the largest sum.

// Return any such subsequence as an integer array of length k.

// A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int>temp=nums;
        sort(nums.rbegin(),nums.rend());
        unordered_map<int,int>mp;
        for(int i=0;i<k;i++){
            mp[nums[i]]++;
        }

        vector<int>ans;
        for(int i=0;i<temp.size();i++){
            if(mp.find(temp[i])!=mp.end()){
                ans.push_back(temp[i]);
                mp[temp[i]]--;
                if(mp[temp[i]]==0)mp.erase(temp[i]);
            }
        }
        return ans;
    }

};

///alternate approach
vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int, int>> vals;  // auxiliary array
        for (int i = 0; i < n; ++i) {
            vals.emplace_back(i, nums[i]);
        }
        // sort by numerical value in descending order
        sort(vals.begin(), vals.end(),
             [&](auto x1, auto x2) { return x1.second > x2.second; });
        // select the first k elements and sort them in ascending order by index
        sort(vals.begin(), vals.begin() + k);
        vector<int> res;  // target subsequence
        for (int i = 0; i < k; ++i) {
            res.push_back(vals[i].second);
        }
        return res;
    }