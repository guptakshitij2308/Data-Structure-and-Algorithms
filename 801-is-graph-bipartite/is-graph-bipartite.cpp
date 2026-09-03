class Solution {
private:
    bool dfs(int node,vector<vector<int>>& graph,vector<int>&vis,vector<int>&col,int colour) {
        vis[node]=1;
        col[node]=colour;
        for(auto &neighbour:graph[node]) {
            if(!vis[neighbour] && !dfs(neighbour,graph,vis,col,!col[node])) return false;
            else if(col[node]==col[neighbour]) return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vis(n,0);
        vector<int>col(n,0);
        for(int i=0;i<n;i++) {
            if(!vis[i] && !dfs(i,graph,vis,col,0)) return false;
        }
        return true;
    }
};