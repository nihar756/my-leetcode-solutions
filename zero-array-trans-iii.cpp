// You are given an integer array nums of length n and a 2D array queries where queries[i] = [li, ri].

// Each queries[i] represents the following action on nums:

// Decrement the value at each index in the range [li, ri] in nums by at most 1.
// The amount by which the value is decremented can be chosen independently for each index.
// A Zero Array is an array with all its elements equal to 0.

// Return the maximum number of elements that can be removed from queries, such that nums can still be 
// converted to a zero array using the remaining queries. If it is not possible to convert nums to a zero array, return -1.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
       int n=nums.size();
       int m=queries.size();
       vector<int>workLoad(n+1,0);
       sort(queries.begin(),queries.end());
       priority_queue<int>available;
       int qIdx=0;
       for(int time=0;time<n;time++){
        if(time>0){
           workLoad[time]+=workLoad[time-1];
        }
        while(qIdx<m && queries[qIdx][0]==time){
            available.push(queries[qIdx][1]);
            qIdx++;
        }
        while(workLoad[time]<nums[time]){
            if(available.empty() || available.top()<time){
                return -1;
            }
            workLoad[time]++;
            workLoad[available.top()+1]--;
            available.pop();
        }
       }
       return available.size();
    }
};