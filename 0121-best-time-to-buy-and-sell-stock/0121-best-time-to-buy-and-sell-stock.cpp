class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
    int s=prices[0],ind=0;
    int m=0;
    for(int i=0;i<n;i++)
    {
        s=min(prices[i],s);
        m=max(m,prices[i]-s);
    }
    return m;
    }
};