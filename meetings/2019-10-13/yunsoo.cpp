class Solution {
public:
    int magicalString(int n) {
        vector<int> s = {1, 2, 2};
        int toggle = 2;
        int s_idx = 2;
        int s_size = s.size();
        int k = 0;
        
        while(s_size < n){
            toggle ^= 3;
            k = s[s_idx];
            for(int i = 0; i < k; i++){
                s.push_back(toggle);
            }
            s_idx++;
            s_size += k;
        }
        
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == 1){
                cnt++;
            }
        }
        return cnt;
    }
};





    
    
