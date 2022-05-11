class Solution {
public:
    
    int helper(int n)
    {
        int countA=1;
        int countE=1;
        int countI=1;
        int countO=1;
        int countU=1;
        while(n>1)
        {
            countO+=countU;
            countI+=countO;
            countE+=countI;
            countA+=countE;
            n--;
        }
        return countA+countE+countI+countO+countU;
    }
    
    int countVowelStrings(int n) {
        return helper(n); 
    }
};