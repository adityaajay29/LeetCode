class Solution {
public:
    int fib(int n) {
        if(n <= 1)
            return n;
        
        int twoStep = 0;
        int oneStep = 1;
        for(int i=2;i<=n;i++)
        {
            int curr = twoStep + oneStep;
            twoStep = oneStep;
            oneStep = curr;
        }
        return oneStep;
    }
};