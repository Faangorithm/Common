#define INF 987654321

int pick(int idx, vector<int>& nums, int target, int num_picked, int local_sum){
    if(num_picked == 3){
        return local_sum;
    }
    if(idx >= nums.size()){
        return INF;
    }
    int m1 = pick(idx + 1, nums, target, num_picked + 1, local_sum + nums[idx]);
    int m2 = pick(idx + 1, nums, target, num_picked, local_sum);
    if(abs(target - m1) < abs(target - m2)){
        return m1;
    }
    return m2;
}

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        return pick(0, nums, target, 0, 0);
    }
};
