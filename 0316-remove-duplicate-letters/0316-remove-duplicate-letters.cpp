class Solution {
public:
        string removeDuplicateLetters(string s) {
        int n = s.size();
        array<int, 26> counts = {};
        for (auto c: s) {
            counts[c-'a']++;
        }
        deque<char> candidate;
        unordered_set<char> pushed;
        for (auto c: s) {
            // not pushed before & less than stack top && will not cause stack top fail
            while (!candidate.empty() && candidate.back() >= c && !pushed.count(c) && counts[candidate.back()-'a']) {
                pushed.erase(candidate.back());
                candidate.pop_back();
            }
            if (!pushed.count(c)) {
                candidate.push_back(c);    
                pushed.insert(c);
            }
            counts[c-'a']--;
        }
        return string(candidate.begin(), candidate.end());
    }
};