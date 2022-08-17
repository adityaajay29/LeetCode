class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
       vector<string> code{
           ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."
       };
        unordered_set<string> s;
        for(string word : words)
        {
            string temp = "";
            for(char c : word)
            {
                temp += code[c - 'a'];
            }
            s.insert(temp);
        }
        return s.size();
    }
};