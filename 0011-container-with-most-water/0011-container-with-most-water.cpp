class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
		//  create two pointer
		// one is for starting point
        int i = 0;
		// second for ending point
        int j = height.size()-1;
        int minimum;
        while(i<j)
        {
		   // find minium between starting wall and ending wall
            minimum = min(height[i],height[j]);
			// find the present area then check with overall area
            maxArea = max(maxArea, minimum*(j-i));
			// if starting wall is greater than ending wall then decreasing ending pointer
            if(height[i] > height[j])j--;
			// else increase start pointer
            else i++;
        }
        return maxArea;
    }
};