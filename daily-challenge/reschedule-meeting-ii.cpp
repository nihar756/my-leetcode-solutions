// You are given an integer eventTime denoting the duration of an event. You are also given two integer arrays startTime and endTime, each of length n.

// These represent the start and end times of n non-overlapping meetings that occur during the event between time t = 0 and time t = eventTime, where the ith meeting occurs during the time [startTime[i], endTime[i]].

// You can reschedule at most one meeting by moving its start time while maintaining the same duration, such that the meetings remain non-overlapping, to maximize the longest continuous period of free time during the event.

// Return the maximum amount of free time possible after rearranging the meetings.

// Note that the meetings can not be rescheduled to a time outside the event and they should remain non-overlapping.

// Note: In this version, it is valid for the relative ordering of the meetings to change after rescheduling one meeting.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size(), res = 0;
        for (int i = 0, t1 = 0, t2 = 0; i < n; i++) {
            int left1 = i == 0 ? 0 : endTime[i - 1];
            int right1 = i == n - 1 ? eventTime : startTime[i + 1];
            if (endTime[i] - startTime[i] <= t1) {
                res = max(res, right1 - left1);
            }
            t1 = max(t1, startTime[i] - (i == 0 ? 0 : endTime[i - 1]));

            res = max(res, right1 - left1 - (endTime[i] - startTime[i]));

            int left2 = i == n - 1 ? 0 : endTime[n - i - 2];
            int right2 = i == 0 ? eventTime : startTime[n - i];
            if (endTime[n - i - 1] - startTime[n - i - 1] <= t2) {
                res = max(res, right2 - left2);
            }
            t2 = max(t2, (i == 0 ? eventTime : startTime[n - i]) -
                             endTime[n - i - 1]);
        }
        return res;
    }
};