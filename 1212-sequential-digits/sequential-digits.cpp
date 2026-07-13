class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>allCombinations;
        for(int i=1;i<9;i++) {
            int sum=i;
            for(int j=i+1;j<10;j++) {
                sum=sum*10+j;
                allCombinations.push_back(sum);
            }
        }
        sort(allCombinations.begin(),allCombinations.end());
        vector<int>ans;
        for(auto &ele:allCombinations) {
            if(ele>=low && ele<=high) ans.push_back(ele);
        }
        return ans;
    }
};