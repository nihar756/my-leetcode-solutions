// You are given an integer num. You know that Bob will sneakily remap one of the 10 possible digits (0 to 9) to another digit.

// Return the difference between the maximum and minimum values Bob can make by remapping exactly one digit in num.

// Notes:

// When Bob remaps a digit d1 to another digit d2, Bob replaces all occurrences of d1 in num with d2.
// Bob can remap a digit to itself, in which case num does not change.
// Bob can remap different digits for obtaining minimum and maximum values respectively.
// The resulting number after remapping can contain leading zeroes.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        int max_val = num, min_val = num;

        // Try all possible mappings for max value (d1 -> d2), with d2 > d1
        for (char d1 = '0'; d1 <= '9'; ++d1) {
            for (char d2 = '0'; d2 <= '9'; ++d2) {
                if (d1 == d2) continue;

                string temp = s;
                for (char& c : temp) {
                    if (c == d1) c = d2;
                }
                int val = stoi(temp);
                max_val = max(max_val, val);
                min_val = min(min_val, val);
            }
        }

        return max_val - min_val;
    }
};