// You are given a string s and a robot that currently holds an empty string t. Apply one of the following operations until s and t are both empty:

// Remove the first character of a string s and give it to the robot. The robot will append this character to the string t.
// Remove the last character of a string t and give it to the robot. The robot will write this character on paper.
// Return the lexicographically smallest string that can be written on the paper.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string robotWithString(string s) {
       stack<char>st;
       vector<int>freq(26,0);
       for(int i=0;i<s.size();i++)freq[s[i]-'a']++;
       int j=0;
       string ans="";
       for(int i=0;i<s.size();i++){
        st.push(s[i]);
        freq[s[i]-'a']--;
        while(j<26 && freq[j]==0)j++;
        while(!st.empty() && (j==26 || st.top()<=j+'a')){
            ans+=st.top();
            st.pop();
        }
       }
       return ans;
    }
};