class Solution {
public:
    vector<string> fullJustify(vector<string>& w, int mw) {
        int cnt=0,i,cw=0,l=0,n=w.size();
        vector<string> ans;
        string t="";
        
        for(i=0;i<n;i++){
            if(cnt+w[i].length()+cw<=mw){
                cnt+=w[i].length(); // no of alphabets added also increases
                cw++; // no of words added increases
                if(i!=(n-1)) // if this is not the last word 
                    continue;
            }
            else
                i--;
            
			// if only 1 word has been added so make it left aligned
            if(cw==1){
                string s=w[l];
                while(s.length()<mw)
                    s=s+" ";
                ans.push_back(s);
                l=i+1;
                cnt=0,cw=0;
                continue;
            }
            
			// for cw words we need cw-1 gaps
            cw--;
			
            int spaces=mw-cnt; // total spaces
            // per - space per gaps
			// rem - no of gaps on left with 1 extra space
			int rem=spaces%cw,per=spaces/cw;
            
            cnt=0,cw=0;
            string sp="",s="";
			
			// uniform gap
            while(per--)
                sp+=" ";
            
			// 1st few gaps filled with per+1 spaces
            while(rem--)
                s=s+w[l++]+sp+" ";
            
			// last gaps which are uniformly filled with "per" spaces
            while(l<i)
                s+=w[l++]+sp;
            
            s+=w[l++];
            ans.push_back(s);
            l=i+1;
        }
		
		// making the last string left aligned
        t=ans[ans.size()-1];
        ans.pop_back();
        bool f=1;
        
        string s="";
        for(auto c:t){
            if(c==' '){
               if(f){
                    s=s+c;
                    f=0;
                }
            }
            else{
                s=s+c;
                f=1;
            }
        }
        
        while(s.length()<mw)
            s=s+" ";
        
        
        ans.push_back(s);
        
        
        return ans;
    }
};