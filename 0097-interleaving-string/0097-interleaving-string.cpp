class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.size() != s1.size() + s2.size())
            return false;
        if (s1.size() > s2.size())
            s1.swap(s2);
        bool dp[s1.size() + 1];
        dp[0] = true;
        for (int i = 0; i < s1.size(); i++) {
            dp[i + 1] = dp[i] && s1[i] == s3[i];
        }
        for (int i = 0; i < s2.size(); i++) {
            dp[0] = dp[0] && s3[i] == s2[i];
            for (int j = 0; j < s1.size(); j++) {
                dp[j + 1] = (dp[j + 1] && s2[i] == s3[i + j + 1]) ||
                            (dp[j] && s1[j] == s3[i + j + 1]);
            }
        }
        
        return dp[s1.size()];
        
    }
};