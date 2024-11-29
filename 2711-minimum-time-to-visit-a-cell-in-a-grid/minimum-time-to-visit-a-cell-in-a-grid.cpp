class Solution {

    struct Point {
        int row{};
        int column{};

        Point() = default;
        Point(int row, int column) : row{row}, column{column}{}
    };

    struct Step {
        int row{};
        int column{};
        int time{};

        Step() = default;
        Step(int row, int column, int time) : row{row}, column{column}, time{time}{}
    };

    struct CompareSteps {
        auto operator()(const Step& first, const Step& second) const {
            return first.time > second.time;
        }
    };

    static const int CAN_NOT_REACH_GOAL = -1;
    inline static const array<array<int, 2>, 4> moves{{ {-1, 0}, {1, 0}, {0, -1}, {0, 1} }};

    int rows = 0;
    int columns = 0;

public:
    int minimumTime(const vector<vector<int>>& matrix) {
        rows = matrix.size();
        columns = matrix[0].size();

        Point start(0, 0);
        Point goal(rows - 1, columns - 1);

        return dijkstraSearchForMinTimeFromStartToGoal(matrix, start, goal);
    }

private:
    int dijkstraSearchForMinTimeFromStartToGoal(span<const vector<int>> matrix, const Point& start, const Point& goal) const {
        // If just one move is possible from the start, then the goal can be reached
        // with appropriate adjustments in the following moves. Otherwise, the goal can not be reached.
        if (notPossibleToMoveFromStart(matrix, start)) {
            return CAN_NOT_REACH_GOAL;
        }

        priority_queue<Step, vector<Step>, CompareSteps> minHeapForTime;
        minHeapForTime.emplace(start.row, start.column, 0);

        vector<vector<int>> minTime = createMinTimeMatrix();
        minTime[start.row][start.column] = 0;

        while (!minHeapForTime.empty()) {

            Step current = minHeapForTime.top();
            minHeapForTime.pop();
            if (current.row == goal.row && current.column == goal.column) {
                break;
            }

            for (const auto& move : moves) {
                int nextRow = current.row + move[0];
                int nextColumn = current.column + move[1];

                if (isInMatrix(nextRow, nextColumn)) {
                    int newTime = calculateNewTime(current.time, matrix[nextRow][nextColumn]);

                    if (newTime < minTime[nextRow][nextColumn]) {
                        minHeapForTime.emplace(nextRow, nextColumn, newTime);
                        minTime[nextRow][nextColumn] = newTime;
                    }
                }
            }
        }

        return minTime[goal.row][goal.column];
    }

    bool notPossibleToMoveFromStart(span<const vector<int>> matrix, const Point& start) const {
        for (const auto& move : moves) {
            int nextRow = start.row + move[0];
            int nextColumn = start.column + move[1];
            if (isInMatrix(nextRow, nextColumn) && matrix[start.row][start.column] + 1 >= matrix[nextRow][nextColumn]) {
                return false;
            }
        }
        return true;
    }

    vector<vector<int>> createMinTimeMatrix() const {
        return vector<vector<int>>(rows, vector<int>(columns, INT_MAX));
    }

    int calculateNewTime(int currentTime, int matrixTime) const {
        return currentTime + 1 >= matrixTime
                ? currentTime + 1
                : matrixTime + (matrixTime - currentTime + 1) % 2;
    }

    bool isInMatrix(int row, int column) const {
        return row >= 0 && row < rows && column >= 0 && column < columns;
    }
};