class Solution {
public:
    double myPow(double x, int n) {
        long long nn = n;
        double ans = 1.0;
        if(nn < 0)
            nn *= -1;
        while(nn)
        {
            if(nn % 2 == 0)
            {
                x *= x;
                nn /= 2;
            }
            else
            {
                ans *= x;
                nn -= 1;
            }
        }
        if(n < 0)
            return (double)(1.0) / (double)(ans);
        else 
            return ans;
    }
};