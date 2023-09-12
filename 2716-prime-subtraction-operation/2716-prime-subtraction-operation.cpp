class Solution {
public:
    bool check(int n)
    {
        if (n <= 1)
		return false;
     	if (n == 2 || n == 3)
	     	return true;
	    if (n % 2 == 0 || n % 3 == 0)
		  return false;
	    for (int i = 5; i <= sqrt(n); i = i + 6)
		   if (n % i == 0 || n % (i + 2) == 0)
			return false;
	    return true;
    }
    bool primeSubOperation(vector<int>& nums) {
        bool fl=true;
        int n=nums.size();
        if(n==1) return true;
        for(int i=1;i<n;i++)
        {
            if(nums[i-1]>=nums[i])
            {
                fl=false;
            }
        }
        if(fl)
        { 
            // when array is already in strictly increasing order.
            return true;
        }
        for(int i=nums[0]-1;i>1;i--)
        {
            if(check(i))
            {
                nums[0]-=i;
                break;
            }
        }
        for(int i=1;i<n;i++)
        {
            int k=nums[i]-nums[i-1];
            if(k<=0) return false;
            for(int j=k-1;j>1;j--)
            {
                if(check(j))
                {
                    nums[i]-=j;
                    break;
                }
            }
        }
        return true;
    }
};