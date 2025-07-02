// Alice is attempting to type a specific string on her computer. However, she tends to be clumsy and may press a key for too long, resulting in a character being typed multiple times.

// You are given a string word, which represents the final output displayed on Alice's screen. You are also given a positive integer k.

// Return the total number of possible original strings that Alice might have intended to type, if she was trying to type a string of size at least k.

// Since the answer may be very large, return it modulo 109 + 7

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mod=1e9+7;

    int possibleStringCount(string word, int k) {
        int n=word.size();
        if(word.empty())return 0;
        vector<int>groups;
        int cnt=1;
        for(int i=1;i<n;i++){
            if(word[i]==word[i-1]){
                cnt++;
            }
            else{
                groups.push_back(cnt);
                cnt=1;
            }
        }
        groups.push_back(cnt);
        long long total=1;
        for(auto num:groups){
            total=(total*num)%mod;
        }
        if(k <= groups.size())return total;
        vector<int>dp(k,0);
        dp[0]=1;
        for(int num:groups){
            vector<int>newDp(k,0);
            long long sum=0;
            for(int s=0;s<k;s++){
                if(s>0)sum=(sum+dp[s-1])%mod;
                if(s>num)sum=(sum-dp[s-num-1]+mod)%mod;
                newDp[s]=sum;
            }
            dp=newDp;
        }
        long long invalid=0;
        for(int s=groups.size();s<k;s++){
            invalid=(invalid+dp[s])%mod;
        }
        return (total-invalid+mod)%mod;
    }
};