class Solution {
   public:
    double getMinDistSum(vector<vector<int>>& positions) {
        double x = 0, y = 0;
        while (true) {
            double sx = 0, sy = 0, s = 0;
            for (vector<int>& c : positions) {
                double cx = c[0], cy = c[1];
                double d = sqrt((x - cx) * (x - cx) + (y - cy) * (y - cy));
                if (d < 1e-10) continue;
                sx += cx / d;
                sy += cy / d;
                s += 1 / d;
            }
            if (s == 0) break;
            double nx = sx / s, ny = sy / s;
            if (abs(nx - x) < 1e-10 && abs(ny - y) < 1e-10) break;
            x = nx, y = ny;
        }
        double ans = 0;
        for (vector<int>& c : positions) {
            double cx = c[0], cy = c[1];
            double d = sqrt((x - cx) * (x - cx) + (y - cy) * (y - cy));
            ans += d;
        }
        return ans;
    }
};