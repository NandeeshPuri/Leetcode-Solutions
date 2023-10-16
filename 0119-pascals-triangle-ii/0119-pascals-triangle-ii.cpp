class Solution {
public:
    std::vector<int> getRow(int rowIndex) {
        std::vector<int> result;
        
        // Initialize the first element of the row to 1.
        result.push_back(1);
        
        // Calculate the `k`-th row using binomial coefficient formula.
        for (int i = 1; i <= rowIndex; i++) {
            // Use the previous element to calculate the current element.
            long long currentElement = static_cast<long long>(result[i - 1]) * (rowIndex - i + 1) / i;
            result.push_back(static_cast<int>(currentElement));
        }
        
        return result;
    }
};