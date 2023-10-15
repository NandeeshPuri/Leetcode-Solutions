class Solution {
public:
    int numWays(int steps, int arrLen) {
        const int kMod = 1e9+7; // Define a modulus value to avoid einteger overflow.
        int n = min(arrLen, steps / 2 + 1); // Calculate the number of positions we need to consider.
        // dp[i] := # of ways to stay on index i
        vector<long> dp(n); // Create an array to store the number of ways to stay at each position.
        dp[0] = 1; // Initialize the number of ways to stay at position 0 after 0 steps to 1.

        while (steps-- > 0) { // Loop through each step.
            vector<long> newDp(n); // Create a new array to store updated values for each position.
            for (int i = 0; i < n; ++i) { // Iterate through each position.
                newDp[i] = dp[i]; // Initialize with the number of ways to stay at the same position in the previous step.
                if (i - 1 >= 0)
                    newDp[i] += dp[i - 1]; // Add the number of ways to reach the current position by moving left.
                if (i + 1 < n)
                    newDp[i] += dp[i + 1]; // Add the number of ways to reach the current position by moving right.
                newDp[i] %= kMod; // Take the modulo to avoid integer overflow.
            }
            dp = newDp; // Update dp with the newDp array for the next step.
        }

        return static_cast<int>(dp[0]); // The final result is stored in dp[0], representing the number of ways to reach the initial position after taking the specified number of steps.
    }
};