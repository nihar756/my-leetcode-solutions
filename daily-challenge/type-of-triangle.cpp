// You are given a 0-indexed integer array nums of size 3 which can form the sides of a triangle.

// A triangle is called equilateral if it has all sides of equal length.
// A triangle is called isosceles if it has exactly two sides of equal length.
// A triangle is called scalene if all its sides are of different lengths.
// Return a string representing the type of triangle that can be formed or "none" if it cannot form a triangle.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string triangleType(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int a=nums[0],b=nums[1],c=nums[2];
        if(a+b>c){
            if(a==b && a==c)return "equilateral";
            else if(a==b || b==c)return "isosceles";
            else return "scalene";
        }
        return "none";
    }
};

////more optimized
class Solution {
public:
    string triangleType(vector<int>& nums) {
        int a = nums[0], b = nums[1], c = nums[2];

        if(a + b > c && b + c > a && a + c > b) {
            if(a == b && b == c && c == a) return "equilateral";
            else if((a == b) || (b == c) || (c == a)) return "isosceles";
            return "scalene";
        }
        return "none";
    }
};