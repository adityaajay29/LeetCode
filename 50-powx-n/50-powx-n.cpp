class Solution {
public:
    
    double ans;
    
    double pow(double x, int n)
    {
        if(n == 0)
            return 1;
        if(n == 1)
            return x;
        ans = x*pow(x, n-1);
        return ans;
    }
    
    double myPow(double x, int n) {
        if(x == 0)
            return 0;
        
        if(x == 1)
            return 1;
        
        if(x == -1)
        {
            return (abs(n)%2 == 0 ? 1 : -1);
        }
        
        if(n == INT_MAX)
        {
            if(x > 1)
                return INT_MAX;
            else if(x < 1)
                return 0;
        }
        
        if(n == INT_MIN)
        {
            if(x > 1 || x < 0)
                return 0;
            else if(x < 1 && x > 0)
                return INT_MAX;
        }
        
        ans = 1;
        
        if(n < 0)
            return pow(1/x, n*(-1));
        else
            return pow(x, n);
    }
};