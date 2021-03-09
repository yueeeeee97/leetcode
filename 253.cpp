class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> starts;
        vector<int> ends;
        for(int i=0;i<n;++i){
            starts.push_back(intervals[i][0]);
            ends.push_back(intervals[i][1]);
        }
        sort(starts.begin(),starts.end());
        sort(ends.begin(),ends.end());
        // int startPos = 0,endPos=0,cnt=0,res=0;
        // while(startPos<n&&endPos<n){
        //     if(starts[startPos]<ends[endPos]){
        //         startPos++;cnt++;
        //     }else{
        //         res = max(res,cnt);
        //         endPos++;cnt--;
        //     }
        // }
        // return max(res,cnt);
        int endPos = 0, res=0;
        for(int startPos = 0;startPos<n;++startPos){
            if(starts[startPos]<ends[endPos]){
                res++;
            }else endPos++;
        }
        return res;
    }
};

//priority_queue
//先把所有的时间区间按照起始时间排序，然后新建一个最小堆，开始遍历时间区间，
//如果堆不为空，且首元素小于等于当前区间的起始时间，去掉堆中的首元素，把当前区间的结束时间压入堆，
//由于最小堆是小的在前面，那么假如首元素小于等于起始时间，说明上一个会议已经结束，可以用该会议室开始下一个会议了，
//所以不用分配新的会议室，遍历完成后堆中元素的个数即为需要的会议室的个数
class Solution {
public:
    static bool cmp(const vector<int>& a,const vector<int>& b){
        return a[0]<b[0];
    }
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if(intervals.empty()) return 0;
        sort(intervals.begin(),intervals.end(),cmp);
        priority_queue<int,vector<int>,greater<>> q;
        for(auto i:intervals){
            if(!q.empty()&&i[0]>=q.top()) q.pop();
            q.push(i[1]);
        }
        return q.size();
    }
};