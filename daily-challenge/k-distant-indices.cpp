// You are given a 0-indexed integer array nums and two integers key and k. A k-distant index is an index i of nums for which there exists at least one index j such that |i - j| <= k and nums[j] == key.

// Return a list of all k-distant indices sorted in increasing order

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        set<int>st;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==key){
                int start=max(0,i-k);
                int end=min(n-1,i+k);
                for(int j=start;j<=end;j++){
                    st.insert(j);
                }

            }
        }
        vector<int>ans(st.begin(),st.end());
        return ans;
    }
};