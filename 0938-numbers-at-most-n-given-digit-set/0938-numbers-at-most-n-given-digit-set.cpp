class Solution {
public:
    int ans = 0;
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string num = to_string(n);
        int ans = 0, max_digits = num.size(), m = digits.size();
        
        for(int i = 1; i < max_digits; i++) {
            ans += pow(m, i);
        }
        
        for(int i = 0; i < max_digits; i++) {
            // binary search element
            int j = lower_bound(begin(digits), end(digits), num[i], [](auto d, auto v){return d[0] < v;}) - begin(digits);
            ans += pow(m, max_digits - 1 - i) * j;
            if(j >= m || digits[j][0] != num[i]) return ans;
        }
        
        return ans + 1;
    }
};