class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
	sort(arr.begin(),arr.end(),[](int &a,int &b){
		//m--> no.of 1's in a
		//n--> no.of 1's in b
		int m=0,n=0;
		for(int i=31;i>=0;i--){
			m=m+((a>>i)&1);
			n=n+((b>>i)&1);
		}
		if(m<n) return true;
		else if(m>n) return false;
		//if no.of ones are same in both values then sort them based on value
		return a<b;
	});
	return arr;
}
};