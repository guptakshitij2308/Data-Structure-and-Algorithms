class Solution {
void dfs(int node,vector<int>adj[],vector<int>&vis,vector<int>&pathVis) {
    vis[node]=1;
    pathVis.push_back(node);
    for(auto &it:adj[node]) {
        if(!vis[it]) dfs(it,adj,vis,pathVis);
    }
}
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        vector<int>vis(n,0);
        for(auto &edge:edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int count=0;
        for(int i=0;i<n;i++) {
            if(!vis[i]) {
                vector<int>pathVis;
                dfs(i,adj,vis,pathVis);
                int sum=0;
                for(auto &it:pathVis) sum+=adj[it].size();
                count+=sum==(pathVis.size()*(pathVis.size()-1))?1:0;
            }
        }
        return count;
    }
};