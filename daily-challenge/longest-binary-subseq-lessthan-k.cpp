// You are given a binary string s and a positive integer k.

// Return the length of the longest subsequence of s that makes up a binary number less than or equal to k.

// Note:

// The subsequence can contain leading zeroes.
// The empty string is considered to be equal to 0.
// A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters

#include<bits/stdc++.h>
using namespace std;

//greedy approach
class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n=s.size();
        long long power=0;
        long long val=0;
        int cnt=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='0'){
                cnt++;
            }
            else if(power<32 && (val+(1LL<<power))<=k){
                cnt++;
                val+=(1LL<<power);
            }
            

            //if(power>=k)break;
            power++;
        }
        return cnt;
    }
};

//dp approach

class Solution {
public:
    int f(int i, int size, int sum, string &s, vector<vector<int>>& dp) {
        if (i < 0) return 0;
        if (dp[i][size] != -1) return dp[i][size];

        int no = f(i - 1, size, sum, s, dp);
        int yes = 0;

        if ((sum - (s[i] - '0') * pow(2, size)) >= 0) {
            yes = 1 + f(i - 1, size + 1, sum - (s[i] - '0') * pow(2, size), s, dp);
        }

        return dp[i][size] = max(no, yes);
    }

    int longestSubsequence(string s, int k) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f(n - 1, 0, k, s, dp);
    }
};