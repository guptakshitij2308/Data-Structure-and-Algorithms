class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        queue<vector<int>>q;
        int n=graph.size();
        vector<vector<int>>ans;
        q.push({0});
        while(!q.empty()) {
            auto front=q.front();
            q.pop();
            if(front.back()==n-1) ans.push_back(front);
            for(auto &it:graph[front.back()]) {
                front.push_back(it);
                q.push(front);
                front.pop_back();
            }
        }
        return ans;
    }
};