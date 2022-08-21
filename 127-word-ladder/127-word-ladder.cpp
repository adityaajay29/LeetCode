class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> set{wordList.begin(), wordList.end()};
        queue<string> q;
        q.push(beginWord);
        int ladder = 1;
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                string word = q.front();
                q.pop();
                if(word == endWord)
                    return ladder;
                
                set.erase(word);
                for(int i=0;i<word.size();i++)
                {
                    char prev = word[i];
                    
                    for(char c = 'a';c <= 'z';c++)
                    {
                        word[i] = c;
                        if(set.find(word) != set.end())
                            q.push(word);
                    }
                    word[i] = prev;
                }
            }
            ladder++;
        }
        return 0;
    }
};