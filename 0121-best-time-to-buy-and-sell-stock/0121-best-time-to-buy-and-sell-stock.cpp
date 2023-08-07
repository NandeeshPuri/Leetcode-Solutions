class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = prices[0];
        int max = prices[0];
        int maxProfit = 0;
        for (int index = 1; index < prices.size(); index++){
            if (max < prices[index]){
                max = prices[index];
            }
            if (index != prices.size()-1 && min > prices[index]){
                if (max - min > maxProfit){
                    maxProfit = max - min;
                }
                min = prices[index];
                max = min;
            }
        }
        if (max - min > maxProfit){
            maxProfit = max - min;
        }
        return maxProfit;
    }
};