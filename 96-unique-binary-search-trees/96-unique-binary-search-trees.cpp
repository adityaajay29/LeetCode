class Solution {
public:
    int numTrees(int n) {
        if(n == 0 || n == 1)
            return 1;
        
        if(n == 2)
            return 2;
        
        int cut = 0;
        for(int k = 0; k < n; k++)
        {
            cut += (numTrees(k) * numTrees(n - k - 1)); 
        }
        return cut;
    }
};