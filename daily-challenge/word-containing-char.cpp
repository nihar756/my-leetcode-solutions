// You are given a 0-indexed array of strings words and a character x.

// Return an array of indices representing the words that contain the character x.

// Note that the returned array may be in any order.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int>idx;
        for(int i=0;i<words.size();i++){
            auto pos=words[i].find(x);
            if(pos!=string::npos){
                idx.push_back(i);
            }
        }
        return idx;
    }
};