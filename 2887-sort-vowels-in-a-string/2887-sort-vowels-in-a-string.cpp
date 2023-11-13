class Solution {
private: 
    bool isVowel(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || 
c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
public:
    string sortVowels(string s) {
        vector<int> vowelFreq(256);
        for(auto chr : s){
           if(isVowel(chr)) 
            vowelFreq[chr]++;
        }
        int freqIndx = 0;
        while(freqIndx < 256 && !vowelFreq[freqIndx])freqIndx++;
        for(int strIndx = 0; strIndx < s.size(); strIndx++){
            if(isVowel(s[strIndx])){
                s[strIndx] = (char)(freqIndx);
                if(--vowelFreq[freqIndx] == 0)freqIndx++;
            }
            while(freqIndx < 256 && !vowelFreq[freqIndx])freqIndx++;
        }
        return s;
    }
};