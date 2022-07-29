class Solution {
public:
    void fib(vector<int> &fibo)
    {
        fibo.push_back(1);
        fibo.push_back(1);
        while(fibo.back() < 1e9 + 1)
        {
            int n = fibo.size();
            fibo.push_back(fibo[n - 1] + fibo[n - 2]);
        }
    }
    
    int findMinFibonacciNumbers(int k) {
        vector<int> fibo;
        fib(fibo);
        int n = fibo.size();
        int count = 0;
        int i = n - 1;
        while(k)
        {
            if(fibo[i] <= k)
            {
                count++;
                k -= fibo[i];
            }
            else
                i--;
        }
        return count;
    }
};