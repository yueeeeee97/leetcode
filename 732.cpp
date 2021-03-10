// meeting room idea
//慢 436ms 5% / 24MB 99%
class MyCalendarThree {
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        starts.push_back(start);
        ends.push_back(end);
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        int i = 0, res = 0;
        for(int j = 0; j < starts.size(); ++j){
            if(starts[j] < ends[i]) ++res;
            else i++;
        }
        return res;
    }
private:
    vector<int> starts, ends;
};

//map 
//96 ms 78% / 26.3 MB 72%
class MyCalendarThree {
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        ++m[start];
        --m[end];
        int res = 0, cnt = 0;
        for(auto iter: m) {
            cnt += iter.second;
            res = max(res, cnt);
        }
        return res;
    }
private:
    map<int, int> m;
};