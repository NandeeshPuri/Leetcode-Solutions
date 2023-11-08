class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        // Calculate the minimum number of steps (Manhattan distance) needed to reach the target.
        int minStep = max(abs(sx - fx),abs(sy - fy));
        
        // If the minimum number of steps is 0, it means we are already at the target cell.
        // In this case, we can reach it only if t is not 1 (meaning we stay at the current cell for t seconds).
        if (minStep == 0) {
            return t != 1;
        }
        
        // If the minimum number of steps is not 0, we need to check if t is greater than or equal to minStep.
        // If t is greater than or equal to minStep, we can reach the target in t seconds.
        return minStep <= t;
    }
};