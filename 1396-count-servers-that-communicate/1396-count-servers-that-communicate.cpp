class Disjointset {
    vector<int> rank, parent, size;
public:
 //constructor
    Disjointset(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
///find ultimate parent function
    int findUpar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUpar(parent[node]);
    }

    void unionbyrank(int u, int v) {
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);
        if (ulp_u == ulp_v) return;//both belong to same compo as both have same ultimateparent
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {//same rank
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionbysize(int u, int v) {
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);
        if (ulp_u == ulp_v) return;//both belong to same compo as both have same ultimateparent
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        //step 1 har row col me kitne server hai (using hashing)
        int n=grid.size();
        int m=grid[0].size();
        vector<int>hash(n+m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    hash[i]++;
                    hash[j+n]++;
                }
            }
        }
//nodes are rows number from 0 to n-1 && then columns from 0 to m-1 but both rows and cols nodes value will be same ,so for columns from n to n+m-1
        //step 2 connecting nodes by dsu
        Disjointset ds(n+m);
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                   ds.unionbysize(i,j+n);
                }
            }
        }
        //step 3  summing up all servers of children of a disjoint  set component
        map<int,int>mp;
        for(int i=0;i<n+m;i++){
            int par=ds.findUpar(i);
            mp[par]+=hash[i];
        }
        //counting servers that can communicate
        int ans=0;
        for(auto i:mp){
           if(i.second>2){
           ans+=(i.second/2);
           }
        }
return ans;
    }
};