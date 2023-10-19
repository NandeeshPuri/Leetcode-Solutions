class Solution {
public:
    int strStr(string h, string f) {
        int ans=-1;

        for(int i=0;i<h.size();i++)
        {
            if(h[i]==f[0])
            {
                ans=i;
                for(int j=0;j<f.size();j++)
                {
                    if(h[i+j]==f[j]) continue;

                    else  
                    {
                     ans=-1;
                     break;

                    }
                }
                if(ans==-1)continue;
                else return ans;
            }
        }
        return ans;
        

    //     if(h.find(f)==string::npos) return -1;

    //    int n=h.size();
    //     int m=f.size();

    //     for(int i=0;i<n-m+1;i++)
    //     {
    //         if(f==h.substr(i,m))
    //         return i;
    //     }
    //     return -1;


    }
};