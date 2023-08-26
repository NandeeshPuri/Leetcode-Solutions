class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;
        
        vector<int> sv(26, 0);
        vector<int> tv(26, 0);
        
        for(int i = 0; i < s.length(); i++){
            sv[s.at(i)-'a']++;
            tv[t.at(i)-'a']++;
        }
        
        return sv == tv;
    }
};