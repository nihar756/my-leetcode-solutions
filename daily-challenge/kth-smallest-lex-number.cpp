// Given two integers n and k, return the kth lexicographically smallest integer in the range [1, n].

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthNumber(int n, int k) {
        long long curr=1;
        k--;
        while(k>0){
            long long cnt=0;
            long long step=1;
            long long first=curr;
            long long last=curr;
            while(first<=n){
                cnt+=min((long long)n+1,last+1)-first;
                first*=10;
                last=last*10+9;
                if(last>n)last=n;
            }
            if(k>=cnt){
                curr++;
                k-=cnt;
            }
            else{
                curr*=10;
                k--;
            }
        }
        return (int)curr;
    }
};