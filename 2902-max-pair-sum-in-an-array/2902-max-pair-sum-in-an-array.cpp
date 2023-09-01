class Solution {
public:
    int maxSum(vector<int>& nums) {
        vector<vector<int>>v(10);
        int x=0,y=0,z=0;
        for(auto &i:nums){
            x=i;y=0;
            while(x){
                z=(x%10);
                y=max(y,z);
                x=x/10;
            }
            v[y].push_back(i);
        }

        int mx1=0,mx2=0,ans=-1;
        for(auto &i:v){
            if(i.size()<=1)continue;

            mx1=0,mx2=0;
            for(auto &j:i){
                if(j>mx1){
                    mx2=mx1;
                    mx1=j;
                }else if(j>mx2){
                    mx2=j;
                }
            }

        ans=max(mx1+mx2,ans);
        }
        return ans;
    }
};