class MyCalendarTwo {
    vector<pair<int, int>> bookings;      // To store single bookings
    vector<pair<int, int>> doubleBookings;  // To store double bookings
    
public:
    MyCalendarTwo() {
        // Constructor
    }
    
    bool book(int start, int end) {
        // Check if the new booking would cause a triple booking
        for (auto &db : doubleBookings) {
            if (max(db.first, start) < min(db.second, end)) {
                return false;  // Overlap with a double booking means triple booking
            }
        }
        
        // Check for overlaps with existing bookings to track double bookings
        for (auto &b : bookings) {
            if (max(b.first, start) < min(b.second, end)) {
                // There's an overlap, so we add this overlap to doubleBookings
                doubleBookings.push_back({max(b.first, start), min(b.second, end)});
            }
        }
        
        // Add the new booking to the single bookings
        bookings.push_back({start, end});
        return true;
    }
};


