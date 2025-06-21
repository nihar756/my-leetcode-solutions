// You are given a string word and an integer k.

// We consider word to be k-special if |freq(word[i]) - freq(word[j])| <= k for all indices i and j in the string.

// Here, freq(x) denotes the frequency of the character x in word, and |y| denotes the absolute value of y.

// Return the minimum number of characters you need to delete to make word k-special.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char,int>mp;
        for(auto c:word)mp[c]++;

        int res=word.size();
        for(auto [_,a]:mp){
            int deleted=0;
            for(auto [_,b]:mp){
                if(a>b){
                    deleted+=b;
                }
                else if(b>a+k){
                    deleted+=b-(a+k);
                }
            }
            res=min(res,deleted);
        }
        return res;
    }
};