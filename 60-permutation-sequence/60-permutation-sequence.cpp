class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> numbers;
        
        int nMinusOneFact = 1;
        for(int i=1;i<n;i++)
        {
            nMinusOneFact *= i;
            numbers.push_back(i);
        }
        numbers.push_back(n);
        
//         making permutaions with 0 based indexing
        k -= 1;
        string kthPerm = "";
        
        while(true)
        {
            kthPerm += to_string(numbers[k / nMinusOneFact]);
            numbers.erase(numbers.begin() + (k / nMinusOneFact));
            if(numbers.size() == 0)
                break;
            k %= nMinusOneFact;
            nMinusOneFact /= numbers.size();
        }
        return kthPerm;
    }
};