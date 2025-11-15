class Solution {
public:
    int maximumSwap(int num) {
        string nums=to_string(num);
        int n=nums.size();
        vector<int>maxIndex(n);
        maxIndex[n-1]=n-1;
        for(int i=n-2;i>=0;i--) {
            if(nums[i]>nums[maxIndex[i+1]]) {
                maxIndex[i]=i;
            }
            else maxIndex[i]=maxIndex[i+1];
        }
        for(int i=0;i<n;i++) {
            if(nums[i]<nums[maxIndex[i]]) {
                swap(nums[i],nums[maxIndex[i]]);
                break;
            }
        }
        return stoi(nums);
    }
};