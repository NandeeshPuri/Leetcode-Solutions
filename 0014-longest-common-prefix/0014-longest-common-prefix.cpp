class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    
        string res= "";
        if(strs.size() == 0)
            return "";
        
        for(int i=0; i<strs[0].size(); i++) // run through each character of first string
        {
            for (int j=1; j<strs.size(); j++)
            {
                if( strs[j][i] != strs[0][i])
                    return res;
                
            }    
            res += strs[0][i];
        }
        
        return res;
    }
};