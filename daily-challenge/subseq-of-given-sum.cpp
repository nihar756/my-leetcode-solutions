// 
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mod=1e9+7;
    int numSubseq(vector<int>& nums, int target) {
        int n=nums.size();
        int lo=0,hi=n-1;
        long long ans=0;
        vector<int>power(n+1,1);
        for(int i=1;i<=n;i++){
            power[i]=(power[i-1]*2)%mod;
        }
        sort(nums.begin(),nums.end());
        while(lo<=hi){
            if(nums[lo]+nums[hi]<=target){
                ans=(ans+power[hi-lo])%mod;
                lo++;
            }
            else{
                hi--;
            }
        }
        return ans;
    }
};