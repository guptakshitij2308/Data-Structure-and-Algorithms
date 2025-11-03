class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans=0;
        int left=0,right=0,n=colors.size();
        while(left<n && right<n) {
            int current=0,maxx=0;
            while(right<n && colors[left]==colors[right]) {
                current+=neededTime[right];
                maxx=max(maxx,neededTime[right]);
                right++;
            }
            ans+=current-maxx;
            left=right;
        }
        return ans;
    }
};