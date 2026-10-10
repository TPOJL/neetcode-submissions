/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> starts;
        vector<int> ends;
        for(auto && el : intervals){
            starts.push_back(el.start);
            ends.push_back(el.end);
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        int num_of_rooms = starts.size();
        int l = 0;
        int r = 0;
    
        while(l != starts.size()) {
            if(starts[l] < ends[r]) l++;
            else{
                l++;
                r++;
                if(r == ends.size()) break;
                num_of_rooms--; 
            };
        }



        return num_of_rooms;
    }
};
