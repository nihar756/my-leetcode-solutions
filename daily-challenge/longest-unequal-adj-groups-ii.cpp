// You are given a string array words, and an array groups, both arrays having length n.

// The hamming distance between two strings of equal length is the number of positions at 
// which the corresponding characters are different.

// You need to select the longest subsequence from an array of indices [0, 1, ..., n - 1], 
// such that for the subsequence denoted as [i0, i1, ..., ik-1] having length k, the following holds:

// (a)For adjacent indices in the subsequence, their corresponding groups are unequal, i.e., 
// groups[ij] != groups[ij+1], for each j where 0 < j + 1 < k.
// (b)words[ij] and words[ij+1] are equal in length, and the hamming distance between them is 1, 
// where 0 < j + 1 < k, for all indices in the subsequence.

// Return a string array containing the words corresponding to the indices (in order) in the selected 
// subsequence. If there are multiple answers, return any of them.

// Note: strings in words may be unequal in length.
#include<bits/stdc++.h>
using namespace std;
///////using dp///////////
class Solution {
public:
    int hm(string &s,string &t){
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]!=t[i])ans++;
        }
        return ans;
    }
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n=words.size();
        vector<vector<string>>list(n);
        vector<int>dp(n+1,0);
        for(int i=0;i<n;i++){
            list[i].push_back(words[i]);
        }
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                string s=words[i];
                string t=words[j];
                if(s.size()==t.size()&&hm(s,t)==1&&groups[i]!=groups[j]){
                    if(dp[j]+1>dp[i]){
                        dp[i]=dp[j]+1;
                        list[i]=list[j];
                        list[i].push_back(words[i]);
                    }
                }
            }
        }
        vector<string>ans;
        int mx=-1;
        for(int i=0;i<n;i++){
           if(dp[i]>mx){
            mx=dp[i];
            ans=list[i];
           }
        }
        //reverse(ans.begin(),ans.end());
        return ans;
    }
};

/////more optimized//////
class Solution {
public:
    bool hamming1(const string& s, const string& t){
        const int sz = s.size();
        if (sz != t.size()) return false;
        int diff = 0;
        for (int i = 0; i < sz && diff < 2; i++)
            diff += s[i] != t[i];
        return diff == 1;
    }

    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        const int n = words.size();
        int maxLen = 0, pos = -1;
        vector<int> dp(n, 1), prev(n, -1);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(groups[i] != groups[j] && hamming1(words[i], words[j])){
                    if(dp[j] + 1 > dp[i]){
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                    }
                }
            }
            if(dp[i] > maxLen){
                maxLen = dp[i];
                pos = i;
            }
        }
        vector<string> ans;
        for(; pos != -1; pos = prev[pos]){
            ans.push_back(words[pos]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};