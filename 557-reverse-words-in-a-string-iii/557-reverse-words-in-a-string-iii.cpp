class Solution {
public:
    string reverseWords(string s) {
        int i=0;
        int n=s.size();
        for(int j=0;j<n;j++)
        {
//             reversing all the words except for last word
            if(s[j] == ' ')
            {
                reverse(s.begin() + i, s.begin() + j);
                i = j + 1;
            }
        }
//         reversing last word
        reverse(s.begin() + i, s.end());
        return s;
    }
};