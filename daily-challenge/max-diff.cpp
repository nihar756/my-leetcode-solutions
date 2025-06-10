// You are given a string s consisting of lowercase English letters.

// Your task is to find the maximum difference diff = a1 - a2 between the frequency of characters a1 and a2 in the string such that:

// a1 has an odd frequency in the string.
// a2 has an even frequency in the string.
// Return this maximum difference.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int>mp;
        for(auto c:s)mp[c]++;
        int oddFreq=INT_MIN;
        int evenFreq=INT_MAX;
        for(auto [c,f]:mp){
            if(f&1)oddFreq=max(oddFreq,f);
            else evenFreq=min(evenFreq,f);
        }
        return oddFreq-evenFreq;
    }
};