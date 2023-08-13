class Solution {
public:
    // used for gradient descent
    double delta = 0.000001;

    // function to calculate distance between two points (x1, y1) and (x2, y2)
    double getDistance(double x1, double y1, double x2, double y2)
    {
        double lengthX = abs(x1 - x2), lengthY = abs(y1 - y2);

        if(lengthX == 0 || lengthY == 0)
            return max(lengthX, lengthY);
        else
            return hypot(lengthX, lengthY);
    }

    // function to calculate the sum of distances between the point 
    // (x1, y1) and all given points
    double getAllDistance(double x1, double y1, vector<vector<int>>& positions)
    {
        double ans = 0.0;

        for(auto ele : positions)
            ans += getDistance(x1, y1, (double)ele[0], (double)ele[1]);

        return ans;
    }

    // function to calculate optimal distance when x is fixed and y varies from minY to maxY
    double getOptimalDistance(double x, double minY, double maxY, vector<vector<int>>& positions)
    {
        // binary search on optimal value of y
        while(minY <= maxY)
        {
            double midY = (minY + maxY)/2.0;

            double dist = getAllDistance(x, midY, positions);
            double distl = getAllDistance(x, midY - delta, positions);
            double distr = getAllDistance(x, midY + delta, positions); 

            if(dist <= distl && dist <= distr)  // midY is the global minimum
                return dist;
            else if(dist > distl)               // midY is to the right of global minimum
                maxY = midY - delta;
            else                                // midY is to the left of global minimum
                minY = midY + delta;
        }

        return min(getAllDistance(x, minY, positions), 
                    getAllDistance(x, maxY, positions));
    }

    double getMinDistSum(vector<vector<int>>& positions) 
    {
        double minX = 101, maxX = -1, minY = 101, maxY = -1; 

        for(auto ele : positions)
        {
            minX = min(minX, (double)ele[0]);
            maxX = max(maxX, (double)ele[0]);
            minY = min(minY, (double)ele[1]);
            maxY = max(maxY, (double)ele[1]);
        }

        // binary search on optimal value of x
        while(minX <= maxX)
        {
            double midX = (minX + maxX)/2.0;

            double dist = getOptimalDistance(midX, minY, maxY, positions);
            double distl = getOptimalDistance(midX - delta, minY, maxY, positions);
            double distr = getOptimalDistance(midX + delta, minY, maxY, positions); 

            if(dist <= distl && dist <= distr)  // midX is the global minimum
                return dist;
            else if(dist > distl)               // midX is to the right of global minimum
                maxX = midX - delta;
            else                                // midX is to the left of global minimum
                minX = midX + delta;
        }

        return min(getOptimalDistance(minX, minY, maxY, positions), 
                    getOptimalDistance(maxX, minY, maxY, positions));
    }
};