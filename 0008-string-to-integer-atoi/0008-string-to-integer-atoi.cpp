class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        while (s[i] == ' ')
            i++;
    
        int sign = 1;
        if (s[i] == '-' or s[i] == '+') 
            sign *= (s[i++] == '-') ? -1 : 1;
        
        while (s[i] == '0')
            i++;
        
        long ans = 0;
        for (int j = 0; i < s.size() and j < 11 and isdigit(s[i]); i++, j++) 
            ans = ans * 10 + s[i] - '0';
        
        ans *= sign;
        if (ans > INT_MAX)
            return INT_MAX;
        if (ans < INT_MIN)
            return INT_MIN;
        return ans;
    }
};