class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        long long sum = 0, sumSquares = 0;
        int n = nums.size();
        for (int num : nums) {
            sum += num;
            sumSquares += 1LL * num * num;
        }

        int m = n - 2;
        long long expectedSum = 1LL * m * (m - 1) / 2;
        long long expectedSquares = 1LL * m * (m - 1) * (2 * m - 1) / 6;

        long long sumDiff = sum - expectedSum;         
        long long squareDiff = sumSquares - expectedSquares; 
        long long product = (sumDiff * sumDiff - squareDiff) / 2;

        double discriminant = (double)sumDiff * sumDiff - 4.0 * product;
        if (discriminant < 0) discriminant = 0;

        double diff = sqrt(discriminant);

        vector<int> ans;
        ans.push_back((int)((sumDiff + diff) / 2));
        ans.push_back((int)((sumDiff - diff) / 2));
        return ans;
    }
};
