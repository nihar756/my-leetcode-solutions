// You are given an integer array digits, where each element is a digit. The array may contain duplicates.

// You need to find all the unique integers that follow the given requirements:

// The integer consists of the concatenation of three elements from digits in any arbitrary order.
// The integer does not have leading zeros.
// The integer is even.
// For example, if the given digits were [1, 2, 3], integers 132 and 312 follow the requirements.

// Return a sorted array of the unique integers.
/////recursive//////
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void solve(int curr,int k,vector<int>&freq,vector<int>&res){
        if(k==0){
            if(curr%2==0)
            res.push_back(curr);
            return;
        }
        curr=curr*10;
        for(int i=0;i<=9;i++){
            if(curr==0 && i==0)continue;
            if(freq[i]>0){
                freq[i]--;
                solve(curr+i,k-1,freq,res);
                freq[i]++;
            }
        }
    }
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int>freq(10,0);
        for(auto it :digits)freq[it]++;
        vector<int>res;
        solve(0,3,freq,res);
        return res;
    }
};
/////iterative/////
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>ans;
        unordered_map<int,int>mp;
        for(int k=0;k<n;k++){
            if(nums[k]%2==0){
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                       if(i!=k && j!=k && i!=j){
                        if(nums[i]!=0 &&nums[j]!=0){
                            int num1=nums[i]*100+nums[j]*10+nums[k];
                            int num2=nums[j]*100+nums[i]*10+nums[k];
                            // if(mp.find(num1)==mp.end())
                            // ans.push_back(num1);
                            // if(mp.find(num2)==mp.end())
                            // ans.push_back(num2);

                            mp[num1]++;
                            mp[num2]++;
                        }
                        else if(nums[i]==0 && nums[j]!=0){
                            int num=nums[j]*100+nums[k];
                            // if(mp.find(num)==mp.end())
                            // ans.push_back(num);
                            mp[num]++;
                        }
                        else if(nums[j]==0 && nums[i]!=0){
                            int num=nums[i]*100+nums[k];
                            // if(mp.find(num)==mp.end())
                            // ans.push_back(num);
                            mp[num]++;
                        }
                       }
                       
                    }
                }
            }
        }
        for(auto it:mp)ans.push_back(it.first);
        sort(ans.begin(),ans.end());
        return ans;
    }
};