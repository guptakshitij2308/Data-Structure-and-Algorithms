class Solution {
public:
    static bool comp(pair<int,int> a, pair<int,int> b) {
        return a.first > b.first || (a.first == b.first && a.second > b.second);
    }

    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;

        for(int i = 0; i + k <= n; i++) {
            unordered_map<int,int> mp;
            vector<pair<int,int>> pq;

            for(int j = i; j < i + k; j++) {
                mp[nums[j]]++;
            }

            for(auto &p : mp) {
                pq.push_back({p.second, p.first});
            }

            sort(pq.begin(), pq.end(), comp);

            int sum = 0;
            for(int j = 0; j < x && j < pq.size(); j++) {
                sum += (pq[j].first*pq[j].second); 
            }

            ans.push_back(sum);
        }

        return ans;
    }
};
