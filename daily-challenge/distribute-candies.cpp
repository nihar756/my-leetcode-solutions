// You are given two positive integers n and limit.

// Return the total number of ways to distribute n candies among 3 children such that no child gets more than limit candies.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ans=0;
        for(int i=0;i<=min(limit,n);i++){
            if(n-i > 2*limit){
                continue;
            }
            ans+=min(n-i,limit)-max(0,n-i-limit)+1;
        }
        return ans;
    }
};