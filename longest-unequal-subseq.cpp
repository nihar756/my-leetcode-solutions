// You are given a string array words and a binary array groups both of length n, where words[i] is associated with groups[i].

// Your task is to select the longest alternating subsequence from words. A subsequence of words is alternating if for any two 
// consecutive strings in the sequence, their corresponding elements in the binary array groups differ. Essentially, you are to 
// choose strings such that adjacent elements have non-matching corresponding bits in the groups array.

// Formally, you need to find the longest subsequence of an array of indices [0, 1, ..., n - 1] denoted as [i0, i1, ..., ik-1], 
// such that groups[ij] != groups[ij+1] for each 0 <= j < k - 1 and then find the words corresponding to these indices.

// Return the selected subsequence. If there are multiple answers, return any of them.
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n=words.size();
        vector<int>dp(n,1);
        vector<int>prev(n,-1);
        int maxLen=1,endIdx=0;
        for(int i=1;i<n;i++){
            int bestLen=1;
            int bestPrev=-1;
            for(int j=i-1;j>=0;j--){
                if(groups[i]!=groups[j] && dp[j]+1>bestLen){
                    bestLen=dp[j]+1;
                    bestPrev=j;
                }
            }
            dp[i]=bestLen;
            prev[i]=bestPrev;
            if(dp[i]>maxLen){
                maxLen=dp[i];
                endIdx=i;
            }
        }
        vector<string>res;
        for(int i=endIdx;i!=-1;i=prev[i]){
            res.push_back(words[i]);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};