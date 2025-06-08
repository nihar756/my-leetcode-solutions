// Given an integer n, return all the numbers in the range [1, n] sorted in lexicographical order.

// You must write an algorithm that runs in O(n) time and uses O(1) extra space. 

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int i,vector<int>&ans,int n){
        if(i>n)return ;
        ans.push_back(i);
        for(int j=0;j<=9;j++){
            solve(i*10+j,ans,n);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int>ans;
        for(int i=1;i<=9;i++){
            solve(i,ans,n);
        }
        return ans;
    }
};