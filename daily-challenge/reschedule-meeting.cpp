// You are given an integer eventTime denoting the duration of an event, where the event occurs from time t = 0 to time t = eventTime.

// You are also given two integer arrays startTime and endTime, each of length n. These represent the start and end time of n non-overlapping meetings, where the ith meeting occurs during the time [startTime[i], endTime[i]].

// You can reschedule at most k meetings by moving their start time while maintaining the same duration, to maximize the longest continuous period of free time during the event.

// The relative order of all the meetings should stay the same and they should remain non-overlapping.

// Return the maximum amount of free time possible after rearranging the meetings.

// Note that the meetings can not be rescheduled to a time outside the event.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n=startTime.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({startTime[i],endTime[i]});
        }
        vector<int>arr;
        arr.push_back(v[0].first);
        for(int i=0;i<n-1;i++){
            arr.push_back(v[i+1].first-v[i].second);
        }
        arr.push_back(eventTime-v.back().second);
        int maxSum=0;
        int sum=0;
        n=arr.size();
        k++;
        for(int i=0;i<min(n,k);i++){
            sum+=arr[i];
        }

        maxSum=max(maxSum,sum);
        for(int i=k;i<n;i++){
            sum-=arr[i-k];
            sum+=arr[i];
            maxSum=max(maxSum,sum);
        }
        return  maxSum;
    }
};