class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int res=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            int x=nums[i];
            res=min(res,abs(x-k));
            for(int j=i-1;j>=0&&(nums[j]|x)!=nums[j];j--)
            {
                nums[j]|=x;
                res=min(res,abs(nums[j]-k));
            }
        }
        return res;
    }
};