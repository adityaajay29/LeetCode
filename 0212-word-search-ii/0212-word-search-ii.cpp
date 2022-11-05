class TrieNode
{
    public : 
    TrieNode *arr[26] = {};
    string* word;
    void insert(string &word)
    {
        TrieNode *curr = this;
        for(char c : word)
        {
            if(curr->arr[c - 'a'] == nullptr)
            {
                curr->arr[c - 'a'] = new TrieNode();
            }
            curr = curr->arr[c - 'a'];
        }
        curr->word = &word;
    }
};

int m, n;
vector<int> dx{1, -1, 0, 0};
vector<int> dy{0, 0, 1, -1};

class Solution {
public:
    void dfs(vector<vector<char>> &board, vector<string> &ans, int i, int j, TrieNode *trie)
    {
        if(i < 0 || i >= m || j < 0 || j >= n || board[i][j] == '*' || trie->arr[board[i][j] - 'a'] == nullptr)
            return;
        
        char curr = board[i][j];
        trie = trie->arr[curr - 'a'];
        if(trie->word != nullptr)
        {
            ans.push_back(*trie->word);
            trie->word = nullptr;
        }
        board[i][j] = '*';
        for(int k=0;k<4;k++)
        {
            int x = i + dx[k], y = j + dy[k];
            dfs(board, ans, x, y, trie);
        }
        board[i][j] = curr;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size(), n = board[0].size();
        vector<string> ans;
        TrieNode trie;
        for(string &s : words)
            trie.insert(s);
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                dfs(board, ans, i, j, &trie);
            }
        }
        return ans;
    }
};