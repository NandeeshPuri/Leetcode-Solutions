class Solution {
public:
    void reverse(string& s, int start, int end){
        while(start < end){
            char t = s[start];
            s[start++] = s[end];
            s[end--] = t;
        }
    }
    string reverseWords(string s) {
        int start = 0;
        int end = 0;
        while(start < s.size() && end < s.size()){
            while(s[end] != ' ' && end < s.size())
                end++;
            
            reverse(s, start, end - 1);
            start = end + 1;
            end = start;
        }
        return s;
    }
};