// You are given an array of events where events[i] = [startDayi, endDayi]. Every event i starts at startDayi and ends at endDayi.

// You can attend an event i at any day d where startTimei <= d <= endTimei. You can only attend one event at any time d.

// Return the maximum number of events you can attend

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        priority_queue<int,vector<int>,greater<>>pq;
        int maxd=0;
        int n=events.size();
        for(int i=0;i<n;i++){
            maxd=max(maxd,events[i][1]);
        }

        sort(events.begin(),events.end());
        int ans=0;
        for(int i=0,j=0;i<=maxd;i++){
            while(j<n && events[j][0]<=i){
                pq.push(events[j][1]);
                j++;
            }
            while(!pq.empty() && pq.top()<i){
                pq.pop();
            }
            if(!pq.empty()){
                pq.pop();
                ans++;
            }
        }
        return ans;
    }
};