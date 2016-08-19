题目描述


Given a collection of intervals, merge all overlapping intervals.

For example,
Given[1,3],[2,6],[8,10],[15,18],
return[1,6],[8,10],[15,18]. 

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> result;
        for(int i = 0; i < intervals.size(); i++){
            insert(result, intervals[i]);
        }
        return result;
    }
    
private:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    	vector<Interval>::iterator it = intervals.begin();
        while(it != intervals.end()){
            if(newInterval.end < it->start){
                intervals.insert(it, newInterval);
                return intervals;
            }else if(newInterval.start > it->end){
                it++;
                continue;
            }else{
                newInterval.start = min(newInterval.start, it->start);
                newInterval.end = max(newInterval.end, it->end);
                it = intervals.erase(it);
            }
        }
        intervals.insert(intervals.end(), newInterval);
        return intervals;
    }
};
