class Solution {
public:
    int removePalindromeSub(string s) {
//         corner case
        if(s.size() == 0)
            return 0;
        
        int l = 0;
        int h = s.size() - 1;
        while(l < h)
        {
            if(s[l] == s[h])
            {
                l++;
                h--;
            }
            else
//                 if the string is not palindrome, then we have 2 operations:
//                 remove all a
//                 remove all b
                return 2;
        }
//         if the whole string is a palindrome, then only 1 step needed
        return 1;
    }
};