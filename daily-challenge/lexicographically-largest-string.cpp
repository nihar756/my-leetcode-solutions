// You are given a string word, and an integer numFriends.

// Alice is organizing a game for her numFriends friends. There are multiple rounds in the game, where in each round:

// word is split into numFriends non-empty strings, such that no previous round has had the exact same split.
// All the split words are put into a box.
// Find the lexicographically largest string from the box after all the rounds are finished.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string answerString(string word, int numFriends) {
        int n=word.size();
        if(numFriends==1)return word;
        char c=*max_element(word.begin(),word.end());
        string max_string="";

        for(int i=0;i<n;i++){
            if(word[i]==c){
                int l=min(n-i,n-numFriends+1);
                if(l<=0)continue;

                string s=word.substr(i,l);
                if(s>max_string){
                    max_string=s;
                }
            }
        }
        return max_string;
    }
};