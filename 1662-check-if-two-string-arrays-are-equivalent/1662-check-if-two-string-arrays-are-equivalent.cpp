class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int i = 0, j = 0, a = 0, b = 0;
        int m = word1.size(), n = word2.size();
        while(i < m && j < n)
        {
            if(word1[i][a++] != word2[j][b++])
                return false;
            
            if(a >= word1[i].size())
            {
                i++;
                a = 0;
            }
            if(b >= word2[j].size())
            {
                j++;
                b = 0;
            }
        }
        return i == m && j == n;
    }
};