bool mycomp(string a,string b){
    return a < b;
}

class Solution {
public:
    
    int find_digs(int a){
        int ans = 0;
        while(a>0){
            a/=10;
            ans++;
        }
        return ans;
    }
    
    int helper(vector<string>& digits,string num){
        int ans = 0;
        int i = 0;
       
        if(num.length() == 0)
            return 1;
        
        while(i<digits.size() && stoi(digits[i]) < (num[0]-'0')){      
			ans += pow(digits.size(),num.length()-1);    /// Adding numbers that start with lesser most significant digit
            i++;
        }
        if(i<digits.size() && stoi(digits[i]) == (num[0]-'0')){
            ans += helper(digits,num.substr(1));   /// calling recursion to find result of numbers that start with the same most significant digit.
        }
        
        return ans;
        
    }
    
    
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        sort(digits.begin(),digits.end(),mycomp);   /// Sorting the digits array
        
        int ans = 0;
        
        int d = find_digs(n);    /// number of digits in the number n
        
        for(int i = 1;i<=d-1;i++){
            ans += pow(digits.size(),i);    /// Addding the number of numbers which have less than d digits
        }
        
        string num="";
        while(n>0){
            num += to_string(n%10);
            n/=10;
        }
        reverse(num.begin(),num.end());   /// converting n to string
        
       ans += helper(digits,num);    /// helper function finds count of numbers strictly less than num
        
        return ans;
 
    }
};