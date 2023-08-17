class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n=heightMap.size();
        int m=heightMap[0].size();
        priority_queue<pair<int,pair<int,int>>> pq;
        
        int vis[n+1][m+1];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0 || j==m-1 ||i==n-1){
                    pq.push({-heightMap[i][j],{i,j}});
                    vis[i][j]=1;
                }
                else{
                    vis[i][j]=-1;
                }
            }
        }
        vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
        int ans=0;
        while(!pq.empty()){
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            int minofmax=-1*pq.top().first;
            pq.pop();
            for(int i=0;i<4;i++){
                int newx= x+dir[i][0];
                int newy= y+dir[i][1];
                
                if(newx>=0 && newx<n && newy>=0 && newy<m &&vis[newx][newy]!=1){
                    vis[newx][newy]=1;
                    if(minofmax>=heightMap[newx][newy]){
                        ans+=minofmax-heightMap[newx][newy];
                    }
                    pq.push({min(-minofmax,-heightMap[newx][newy]),{newx,newy}});
                }
               
            }
        }
        return ans;
    }
};