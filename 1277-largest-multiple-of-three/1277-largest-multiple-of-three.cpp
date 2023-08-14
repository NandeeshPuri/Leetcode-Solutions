class Solution {
public:
    bool solve(vector<int>& digits, int rem, int k, pair<int, int> &idx){
        for(int i=digits.size()-1; i>=0; i--){
            if(digits[i] % 3 == rem){
                if(idx.first == -1) idx.first = i;
                else idx.second = i;

                k--;
                if(k == 0) return true;
            }
        }

        return false;
    }

    string makeStr(vector<int>& digits, pair<int, int> &idx){
        string ans = "";

        for(int i=0; i<digits.size(); i++){
            if(idx.first == i || idx.second == i) continue;
            if(digits[i] == 0 && ans.size() == 0) return "0";

            ans += (digits[i] + '0');
        }

        return ans;
    }

    string largestMultipleOfThree(vector<int>& digits) {
        sort(digits.begin(), digits.end(), greater<int>());
        int sum = 0;
        for(auto i : digits) sum += i;

        pair<int, int> idx = {-1,-1};
        if(sum % 3 == 0) return makeStr(digits, idx);
        else if(sum % 3 == 1){
            bool flag = solve(digits, 1, 1, idx);
            if(!flag) solve(digits, 2, 2, idx);
        }
        else if(sum % 3 == 2){
            bool flag = solve(digits, 2, 1, idx);
            if(!flag) solve(digits, 1, 2, idx);
        }

        return makeStr(digits, idx);
    }
};