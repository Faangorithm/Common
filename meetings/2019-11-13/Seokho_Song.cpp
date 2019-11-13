//Author Seokho Song
//Date 2019-11-13
//URL https://leetcode.com/problems/knight-dialer/
//Approach DP
class Solution {
public:
    long long dp[5001][10]={{1,1,1,1,1,1,1,1,1,1}};
    
    long long cal(int N, int digit)
    {
        if(N<0)
            return 0;
        if(dp[N][digit])
            return dp[N][digit];
        long long c = 0;
        switch(digit)
        {
            case 0:
                c = cal(N-1, 4) % 1000000007;
                c += cal(N-1, 6) % 1000000007;
                break;
            case 1:
                c = cal(N-1, 8) % 1000000007 ;
                c += cal(N-1, 6) % 1000000007;
                break;
            case 2:
                c = cal(N-1, 7) % 1000000007;
                c += cal(N-1, 9) % 1000000007;
                break;
            case 3:
                c = cal(N-1, 4)% 1000000007;
                c += cal(N-1, 8) % 1000000007;
                break;
            case 4:
                c = cal(N-1, 3)%1000000007;
                c+=cal(N-1, 9)%1000000007;
                c+=cal(N-1, 0)%1000000007;
                break;
            case 5:
                break;
            case 6:
                c = cal(N-1, 1)%1000000007;
                c+=cal(N-1, 7)%1000000007;
                c+=cal(N-1, 0)%1000000007;
                break;
            case 7:
                c = cal(N-1, 2)%1000000007;
                c += cal(N-1, 6)%1000000007;
                break;
            case 8:
                c = cal(N-1, 1)%1000000007;
                c += cal(N-1, 3)%1000000007;
                break;
            case 9:
                c = cal(N-1, 2)%1000000007;
                c += cal(N-1, 4)%1000000007;
                break;
       
        }
        return dp[N][digit] = c % 1000000007;
    }
    
    int knightDialer(int N) {
        int ans = 0;
        for(int i=0;i<10;i++)
        {
            ans+= cal(N-1,i) % 1000000007;
            ans = ans % 1000000007;
        }
        return ans;
    }
};