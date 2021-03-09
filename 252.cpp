class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(), [](const vector<int>&a, const vector<int>&b){return a[0]<b[0];});
        for(int i=1;i<intervals.size();++i){
            if(intervals[i][0]<intervals[i-1][1]) return false;
        }
        return true;
    }
};
///////
class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        vector<int> starts,ends;
        int n = intervals.size();
        for(int i=0;i<n;++i){
            starts.push_back(intervals[i][0]);
            ends.push_back(intervals[i][1]);
        }
        sort(starts.begin(),starts.end());
        sort(ends.begin(),ends.end());
        for(int i=1;i<n;++i){
            if(starts[i]<ends[i-1]) return false;
        }
        return true;
    }
};