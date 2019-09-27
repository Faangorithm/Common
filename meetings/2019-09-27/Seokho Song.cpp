//Author    Seokho Song
//Date 2019-09-27
//URL   https://leetcode.com/problems/3sum-closest/submissions/
//Approach Brute Force
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int cs = 0x7FFFFFFF;
        int res = 0;
        for(int i=0;i<nums.size()-2;i++)
        {
            for(int j=i+1;j<nums.size()-1; j++)
            {   
                for(int k=j+1;k<nums.size();k++)
                {
                    int p = abs((nums[i] + nums[j]+nums[k]) - target);
                 
                    if(p < cs)
                    {
                        cs =p;
                        res = nums[i] + nums[j]+nums[k];
                    }
                }
            }
        }
        return res;
    }
}
