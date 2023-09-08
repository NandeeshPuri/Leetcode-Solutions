class Solution {
public:
long long dp[101][2][2][11];//position,tight,leading zeroes,prev digit
long long mod=1e9+7;
bool check(string low) {
    for (long long i = 1; i < low.size(); i++) {
        long long a = low[i - 1] - '0';
        long long b = low[i] - '0';
        if (abs(b - a) != 1) {
            return false;
        }
    }
    return true;
}

long long helper(string s,long long pos,long long tight,long long zero,long long prev){
    if(pos==s.size()){
        
        if(zero)return 0;
        return 1;
    }
    if(dp[pos][tight][zero][prev]!=-1)return dp[pos][tight][zero][prev];
    long long limit=(tight==1)?s[pos]-'0':9;
    long long res=0;
    for(long long i=0;i<=limit;i++){
        if(zero && i==0){
            res=(res+helper(s,pos+1,tight&(i==limit),1,0))%mod;
        }
        else if(zero && i>0){
            res=(res+helper(s,pos+1,tight&(i==limit),0,i))%mod;
        }
        else{//this case is when zero==0
            if(abs(i-prev)==1){
                res=(res+helper(s,pos+1,tight&(i==limit),0,i))%mod;
            }
        }
    }
     return dp[pos][tight][zero][prev]=res%mod;
}
    int countSteppingNumbers(string low, string high) {
        memset(dp,-1,sizeof(dp));
        long long a=(helper(high,0,1,1,0))%mod;
        
        memset(dp,-1,sizeof(dp));
        long long b=(helper(low,0,1,1,0))%mod;
        
        long long extra=0;
        cout<<a<<" "<<b;
        if(check(low))
        extra++;
        
        
        return (a-b+extra+mod)%mod;
        
    }
};