class Solution {
private:
    void explore(int row,int col,vector<vector<int>>&unguarded) {
        for(int i=row-1;i>=0;i--) {
            if(unguarded[i][col]==2 || unguarded[i][col]==1) break;
            unguarded[i][col]=3;
        }
        for(int i=row+1;i<unguarded.size();i++) {
            if(unguarded[i][col]==2 || unguarded[i][col]==1) break;
            unguarded[i][col]=3;
        }
        for(int i=col-1;i>=0;i--) {
            if(unguarded[row][i]==2 || unguarded[row][i]==1) break;
            unguarded[row][i]=3;
        }
        for(int i=col+1;i<unguarded[0].size();i++) {
            if(unguarded[row][i]==2 || unguarded[row][i]==1) break;
            unguarded[row][i]=3;
        }
    }
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>unguarded(m,vector<int>(n,0));
        for(int i=0;i<guards.size();i++) {
            unguarded[guards[i][0]][guards[i][1]]=1;
        }
        for(int i=0;i<walls.size();i++) {
            unguarded[walls[i][0]][walls[i][1]]=2;
        }
        for(auto &guard:guards) {
            explore(guard[0],guard[1],unguarded);
        }
        int ans=0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(unguarded[i][j]==0) ans++;
            }
        }
        return ans;

    }
};