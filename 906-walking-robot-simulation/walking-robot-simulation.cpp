class Solution {
public:
    int robotSim(std::vector<int>& commands, std::vector<std::vector<int>>& obstacles) {
        // Directions: North (0, 1), East (1, 0), South (0, -1), West (-1, 0)
        std::vector<std::pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int x = 0, y = 0;  // Robot's starting position
        int dir = 0;  // Index for the current direction (starting facing north)
        
        // Store obstacles in a set for quick lookup
        std::unordered_set<std::string> obstacleSet;
        for (const auto& obstacle : obstacles) {
            obstacleSet.insert(std::to_string(obstacle[0]) + "," + std::to_string(obstacle[1]));
        }
        
        int maxDistanceSquared = 0;
        
        for (int command : commands) {
            if (command == -2) {
                // Turn left 90 degrees
                dir = (dir + 3) % 4;
            } else if (command == -1) {
                // Turn right 90 degrees
                dir = (dir + 1) % 4;
            } else {
                // Move forward 'command' steps in the current direction
                for (int i = 0; i < command; ++i) {
                    int nx = x + directions[dir].first;
                    int ny = y + directions[dir].second;
                    
                    if (obstacleSet.find(std::to_string(nx) + "," + std::to_string(ny)) == obstacleSet.end()) {
                        // If there's no obstacle, move to the new position
                        x = nx;
                        y = ny;
                        // Calculate the squared distance from the origin
                        maxDistanceSquared = std::max(maxDistanceSquared, x * x + y * y);
                    } else {
                        // Obstacle encountered, stop moving in this direction
                        break;
                    }
                }
            }
        }
        
        return maxDistanceSquared;
    }
};
