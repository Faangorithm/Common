//Author Seokho Song
//Date 2019-11-06
//URL https://leetcode.com/problems/gas-station
//Approach Twopointer, PartialSum

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> dt;
        int sum=0;
        
        for(int i=0;i<cost.size()*2;i++)
        {
            dt.push_back(gas[i%cost.size()]-cost[i%cost.size()]);            
        }
           
        int left = 0;
        int right = 1;
        
        int c = dt[left];
        
        while(left < gas.size()*2 && abs(left-right) < gas.size())
        {
            while(c < 0 && left < right)
            {
                c -= dt[left];
                left++;
                
            }
            c+= dt[right];
            right++;
        }
        
        if(abs(left-right) == gas.size() && c >=0)
            return left;
        return -1;
        

    }
};