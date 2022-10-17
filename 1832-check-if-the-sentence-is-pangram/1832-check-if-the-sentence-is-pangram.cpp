class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> ascii(26, 0);
        for(char c : sentence)
            ascii[c - 'a']++;
        
        for(int x : ascii)
            if(x == 0)
                return false;
        
        return true;
    }
};