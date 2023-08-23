// BRUTE FORCE (using Heap)
/*
TC : O(n.logn) // heap -> push(),pop() for n elements
SC : O(n) // heap
*/
class Solution {
public:
    string reorganizeString(string s) {
        string ans = "";

        // create map to store characters and their frequencies
        unordered_map<char,int> map; // SC: O(1)
        
        int n = s.length();
        for(int i = 0; i < n; i++) { // TC: O(n)
            map[s[i]]++;
        }

        priority_queue<pair<int,char>> pq; // max heap of pair type - {freq, char}

        // put characters having (freq > 0) in max heap
        for(int i = 'a'; i <= 'z'; i++) { // TC: O(1)
            if(map[i]) {
                pq.push(make_pair(map[i], i));
                cout << pq.top().first << " " << pq.top().second << endl;
            }
        }

        if(pq.top().first > (n+1)/2) // TC: O(logn)
            return ans; // ans is empty
        
        // add characters in 'ans' string having highest freq which is not selected just before
        pair<int,char> prev = {-1,'#'};
        while(!pq.empty()) { // TC: O(n.logn)
            pair<int,char> curr = pq.top();
            pq.pop();
            ans = ans + curr.second;
            if(prev.first > 0) {
                pq.push(prev);
            }
            curr.first--;
            prev = curr;
        }

        return ans;
    }
};