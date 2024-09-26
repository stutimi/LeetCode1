class MyCalendar {
private:
    vector<pair<int, int>> events; // to store booked events as pairs of (start, end)

public:
    MyCalendar() {
        // initialize the calendar
    }
    
    bool book(int start, int end) {
        for (auto &event : events) {
            if (max(event.first, start) < min(event.second, end)) {
                return false; 
            }
        }
       
        events.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */