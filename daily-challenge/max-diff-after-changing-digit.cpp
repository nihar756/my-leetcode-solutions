// You are given an integer num. You will apply the following steps to num two separate times:

// Pick a digit x (0 <= x <= 9).
// Pick another digit y (0 <= y <= 9). Note y can be equal to x.
// Replace all the occurrences of x in the decimal representation of num by y.
// Let a and b be the two results from applying the operation to num independently.

// Return the max difference between a and b.

// Note that neither a nor b may have any leading zeros, and must not be 0.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDiff(int num) {
        string s=to_string(num);
        int max_num=num,min_num=num;
        for(auto d1='0';d1<='9';d1++){
            for(auto d2='0';d2<='9';d2++){
                if(s[0]==d1 && d2=='0')continue;
                string temp=s;
                for(auto &c:temp){
                    if(c==d1)c=d2;
                }
                int n=stoi(temp);
                max_num=max(max_num,n);
                min_num=min(min_num,n);
            }
        }
        return max_num-min_num;
    }
};